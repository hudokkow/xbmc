# parse version.txt and libKODI_guilib.h to get the version and API info
include(${CORE_SOURCE_DIR}/project/cmake/scripts/common/Macros.cmake)
core_find_versions()

### copy all the addon binding header files to include/kodi
# make sure include/kodi exists and is empty
set(APP_LIB_DIR ${DEPENDS_PATH}/lib/${APP_NAME_LC})
if(NOT EXISTS "${APP_LIB_DIR}/")
  file(MAKE_DIRECTORY ${APP_LIB_DIR})
endif()

set(APP_DATA_DIR ${DEPENDS_PATH}/share/${APP_NAME_LC})
if(NOT EXISTS "${APP_DATA_DIR}/")
  file(MAKE_DIRECTORY ${APP_DATA_DIR})
endif()

set(APP_INCLUDE_DIR ${DEPENDS_PATH}/include/${APP_NAME_LC})
if(NOT EXISTS "${APP_INCLUDE_DIR}/")
  file(MAKE_DIRECTORY ${APP_INCLUDE_DIR})
endif()

# make sure C++11 is always set
if(NOT WIN32)
  string(REGEX MATCH "-std=(gnu|c)\\+\\+11" cxx11flag "${CMAKE_CXX_FLAGS}")
  if(NOT cxx11flag)
    set(CXX11_SWITCH "-std=c++11")
  endif()
endif()

# generate the proper KodiConfig.cmake file
configure_file(${CORE_SOURCE_DIR}/project/cmake/KodiConfig.cmake.in ${APP_LIB_DIR}/KodiConfig.cmake @ONLY)

# copy cmake helpers to lib/kodi
file(COPY ${CORE_SOURCE_DIR}/project/cmake/scripts/common/AddonHelpers.cmake
          ${CORE_SOURCE_DIR}/project/cmake/scripts/common/AddOptions.cmake
     DESTINATION ${APP_LIB_DIR})

### copy all the addon binding header files to include/kodi
# parse addon-bindings.mk to get the list of header files to copy
core_file_read_filtered(bindings ${CORE_SOURCE_DIR}/xbmc/addons/addon-bindings.mk)
foreach(binding ${bindings})
  string(REPLACE " =" ";" binding "${binding}")
  string(REPLACE "+=" ";" binding "${binding}")
  list(GET binding 1 header)
  # copy the header file to include/kodi
  configure_file(${CORE_SOURCE_DIR}/${header} ${APP_INCLUDE_DIR} COPYONLY)
endforeach()

### on windows we need a "patch" binary to be able to patch 3rd party sources
### and an unzip binary to process downloaded files
if(WIN32)
  find_program(PATCH_FOUND NAMES patch patch.exe)
  if(PATCH_FOUND)
    message(STATUS "patch utility found at ${PATCH_FOUND}")
  else()
    set(PATCH_ARCHIVE_NAME "patch-2.5.9-7-bin-3")
    set(PATCH_ARCHIVE "${PATCH_ARCHIVE_NAME}.zip")
    set(PATCH_URL "${APP_MIRRORS}/build-deps/win32/${PATCH_ARCHIVE}")
    set(PATCH_DOWNLOAD ${BUILD_DIR}/download/${PATCH_ARCHIVE})

    # download the archive containing patch.exe
    message(STATUS "Downloading patch utility from ${PATCH_URL}...")
    file(DOWNLOAD "${PATCH_URL}" "${PATCH_DOWNLOAD}" STATUS PATCH_DL_STATUS LOG PATCH_LOG SHOW_PROGRESS)
    list(GET PATCH_DL_STATUS 0 PATCH_RETCODE)
    if(NOT ${PATCH_RETCODE} EQUAL 0)
      message(FATAL_ERROR "ERROR downloading ${PATCH_URL} - status: ${PATCH_DL_STATUS} log: ${PATCH_LOG}")
    endif()

    # extract the archive containing patch.exe
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzvf ${PATCH_DOWNLOAD}
                    WORKING_DIRECTORY ${BUILD_DIR})

    # make sure the extraction worked and that patch.exe is there
    set(PATCH_PATH ${BUILD_DIR}/${PATCH_ARCHIVE_NAME})
    set(PATCH_BINARY_PATH ${PATCH_PATH}/bin/patch.exe)
    if(NOT EXISTS ${PATCH_PATH} OR NOT EXISTS ${PATCH_BINARY_PATH})
      message(FATAL_ERROR "ERROR extracting patch utility from ${PATCH_DOWNLOAD_DIR}")
    endif()

    # copy patch.exe into the output directory
    file(INSTALL ${PATCH_BINARY_PATH} DESTINATION ${DEPENDS_PATH}/bin)

    # make sure that cmake can find the copied patch.exe
    find_program(PATCH_FOUND NAMES patch patch.exe)
    if(NOT PATCH_FOUND)
      message(FATAL_ERROR "ERROR installing patch utility from ${PATCH_BINARY_PATH} to ${DEPENDS_PATH}/bin")
    endif()
  endif()

  find_program(7ZIP_FOUND NAMES 7z 7za 7z.exe 7za.exe)
  if(7ZIP_FOUND)
    message(STATUS "7-Zip utility found at ${7ZIP_FOUND}")
  else()
    set(7ZIP_ARCHIVE_NAME "7z-9.20-bin")
    set(7ZIP_ARCHIVE "${7ZIP_ARCHIVE_NAME}.zip")
    set(7ZIP_URL "http://mirrors.kodi.tv/build-deps/win32/${7ZIP_ARCHIVE}")
    set(7ZIP_DOWNLOAD ${BUILD_DIR}/download/${7ZIP_ARCHIVE})

    # download the archive containing 7za.exe
    message(STATUS "Downloading 7-Zip utility from ${7ZIP_URL}...")
    file(DOWNLOAD "${7ZIP_URL}" "${7ZIP_DOWNLOAD}" STATUS 7ZIP_DL_STATUS LOG 7ZIP_LOG SHOW_PROGRESS)
    list(GET 7ZIP_DL_STATUS 0 7ZIP_RETCODE)
    if(NOT ${7ZIP_RETCODE} EQUAL 0)
      message(FATAL_ERROR "ERROR downloading ${7ZIP_URL} - status: ${7ZIP_DL_STATUS} log: ${7ZIP_LOG}")
    endif()

    # extract the archive containing 7za.exe
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzvf ${7ZIP_DOWNLOAD}
                    WORKING_DIRECTORY ${BUILD_DIR})

    # make sure the extraction worked and that 7za.exe is there
    set(7ZIP_PATH ${BUILD_DIR}/${7ZIP_ARCHIVE_NAME})
    set(7ZIP_BINARY_PATH ${7ZIP_PATH}/7za.exe)
    if(NOT EXISTS ${7ZIP_PATH} OR NOT EXISTS ${7ZIP_BINARY_PATH})
      message(FATAL_ERROR "ERROR extracting 7-Zip utility from ${7ZIP_PATH}")
    endif()

    # copy 7za.exe into the output directory
    file(INSTALL ${7ZIP_BINARY_PATH} DESTINATION ${DEPENDS_PATH}/bin)

    # make sure that cmake can find the copied 7za.exe
    find_program(7ZIP_FOUND NAMES 7z 7za 7z.exe 7za.exe)
    if(NOT 7ZIP_FOUND)
      message(FATAL_ERROR "ERROR installing 7-Zip utility from ${7ZIP_BINARY_PATH} to ${DEPENDS_PATH}/bin")
    endif()
  endif()
endif()
