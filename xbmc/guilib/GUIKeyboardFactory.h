#pragma once

/*
 *      Copyright (C) 2005-present Team Kodi
 *      http://kodi.tv
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

#include "GUIKeyboard.h"
#include <string>

class CVariant;

class CGUIKeyboardFactory
{

  public:
    CGUIKeyboardFactory(void);
    virtual ~CGUIKeyboardFactory(void);

    static bool ShowAndGetInput(std::string& aTextString, bool allowEmptyResult, unsigned int autoCloseMs = 0);
    static bool ShowAndGetInput(std::string& aTextString, CVariant heading, bool allowEmptyResult, bool hiddenInput = false, unsigned int autoCloseMs = 0);
    static bool ShowAndGetNewPassword(std::string& strNewPassword, unsigned int autoCloseMs = 0);
    static bool ShowAndGetNewPassword(std::string& newPassword, CVariant heading, bool allowEmpty, unsigned int autoCloseMs = 0);
    static bool ShowAndVerifyNewPassword(std::string& strNewPassword, unsigned int autoCloseMs = 0);
    static bool ShowAndVerifyNewPassword(std::string& newPassword, CVariant heading, bool allowEmpty, unsigned int autoCloseMs = 0);
    static int  ShowAndVerifyPassword(std::string& strPassword, const std::string& strHeading, int iRetries, unsigned int autoCloseMs = 0);
    static bool ShowAndGetFilter(std::string& aTextString, bool searching, unsigned int autoCloseMs = 0);

    static bool SendTextToActiveKeyboard(const std::string &aTextString, bool closeKeyboard = false);

    static bool isKeyboardActivated() { return g_activeKeyboard != NULL; }
  private:
    static CGUIKeyboard *g_activeKeyboard;
    static FILTERING m_filtering;
    static void keyTypedCB(CGUIKeyboard *ref, const std::string &typedString);
};
