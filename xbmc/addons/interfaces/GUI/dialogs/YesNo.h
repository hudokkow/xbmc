#pragma once
/*
 *      Copyright (C) 2005-present Team Kodi
 *      This file is part of Kodi - https://kodi.tv
 *
 *  Kodi is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Kodi is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kodi. If not, see <https://www.gnu.org/licenses/>.
 *
 */

extern "C"
{
  
struct AddonGlobalInterface;

namespace ADDON
{

  /*!
   * @brief Global gui Add-on to Kodi callback functions
   *
   * To hold functions not related to a instance type and usable for
   * every add-on type.
   *
   * Related add-on header is "./xbmc/addons/kodi-addon-dev-kit/include/kodi/gui/dialogs/YesNo.h"
   */
  struct Interface_GUIDialogYesNo
  {
    static void Init(AddonGlobalInterface* addonInterface);
    static void DeInit(AddonGlobalInterface* addonInterface);

    /*!
     * @brief callback functions from add-on to kodi
     *
     * @note To add a new function use the "_" style to directly identify an
     * add-on callback function. Everything with CamelCase is only to be used
     * in Kodi.
     *
     * The parameter `kodiBase` is used to become the pointer for a `CAddonDll`
     * class.
     */
    //@{
    static bool show_and_get_input_single_text(void* kodiBase,
                                               const char* heading,
                                               const char* text,
                                               bool* canceled,
                                               const char* noLabel,
                                               const char* yesLabel);

    static bool show_and_get_input_line_text(void* kodiBase,
                                             const char* heading,
                                             const char* line0,
                                             const char* line1,
                                             const char* line2,
                                             const char* noLabel,
                                             const char* yesLabel);

    static bool show_and_get_input_line_button_text(void* kodiBase,
                                                    const char* heading,
                                                    const char* line0,
                                                    const char* line1,
                                                    const char* line2,
                                                    bool* canceled,
                                                    const char* noLabel,
                                                    const char* yesLabel);
    //@}
  };

} /* namespace ADDON */
} /* extern "C" */
