if(NOT prefix)
  set(prefix ${CMAKE_INSTALL_PREFIX})
else()
  set(CMAKE_INSTALL_PREFIX ${prefix})
endif()
if(NOT exec_prefix)
  set(exec_prefix ${prefix})
endif()
if(NOT libdir)
  set(libdir ${prefix}/lib)
endif()
if(NOT bindir)
  set(bindir ${prefix}/bin)
endif()
if(NOT includedir)
  set(includedir ${prefix}/include)
endif()
if(NOT datarootdir)
  set(datarootdir ${prefix}/share)
endif()
if(NOT datadir)
  set(datadir ${datarootdir})
endif()

list(APPEND final_message "-- PATH config --")
list(APPEND final_message "Prefix: ${prefix}")
list(APPEND final_message "Libdir: ${libdir}")
list(APPEND final_message "Bindir: ${bindir}")
list(APPEND final_message "Includedir: ${includedir}")
list(APPEND final_message "Datarootdir: ${datarootdir}")
list(APPEND final_message "Datadir: ${datadir}")

set(PATH_DEFINES -DBIN_INSTALL_PATH=\"${libdir}/kodi\"
                 -DINSTALL_PATH=\"${datarootdir}/kodi\")
