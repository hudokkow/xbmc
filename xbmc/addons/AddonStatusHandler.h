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

#include "threads/Thread.h"
#include "IAddon.h"
#include "addons/kodi-addon-dev-kit/include/kodi/xbmc_addon_types.h"
#include "threads/CriticalSection.h"
#include <string>

namespace ADDON
{
  /**
  * Class - CAddonStatusHandler
  * Used to inform the user about occurred errors and
  * changes inside Add-on's, and ask him what to do.
  * It can executed in the same thread as the calling
  * function or in a separate thread.
  */
  class CAddonStatusHandler : private CThread
  {
    public:
      CAddonStatusHandler(const std::string &addonID, ADDON_STATUS status, std::string message, bool sameThread = true);
      ~CAddonStatusHandler() override;

      /* Thread handling */
      void Process() override;
      void OnStartup() override;
      void OnExit() override;

    private:
      static CCriticalSection   m_critSection;
      AddonPtr                  m_addon;
      ADDON_STATUS              m_status;
      std::string               m_message;
  };


}
