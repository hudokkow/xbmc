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

#include "PeripheralNyxboard.h"
#include "PeripheralHID.h"
#include "utils/log.h"
#include "Application.h"

using namespace PERIPHERALS;

CPeripheralNyxboard::CPeripheralNyxboard(CPeripherals& manager, const PeripheralScanResult& scanResult, CPeripheralBus* bus) :
  CPeripheralHID(manager, scanResult, bus)
{
  m_features.push_back(FEATURE_NYXBOARD);
}

bool CPeripheralNyxboard::LookupSymAndUnicode(XBMC_keysym &keysym, uint8_t *key, char *unicode)
{
  std::string strCommand;
  if (keysym.sym == XBMCK_F7 && keysym.mod == XBMCKMOD_NONE && GetSettingBool("enable_flip_commands"))
  {
    /* switched to keyboard side */
    CLog::Log(LOGDEBUG, "%s - switched to keyboard side", __FUNCTION__);
    strCommand = GetSettingString("flip_keyboard");
  }
  else if (keysym.sym == XBMCK_F7 && keysym.mod == XBMCKMOD_LCTRL && GetSettingBool("enable_flip_commands"))
  {
    /* switched to remote side */
    CLog::Log(LOGDEBUG, "%s - switched to remote side", __FUNCTION__);
    strCommand = GetSettingString("flip_remote");
  }

  if (!strCommand.empty())
  {
    CLog::Log(LOGDEBUG, "%s - executing command '%s'", __FUNCTION__, strCommand.c_str());
    if (g_application.ExecuteXBMCAction(strCommand))
    {
      *key = 0;
      *unicode = (char) 0;
      return true;
    }
  }

  return false;
}
