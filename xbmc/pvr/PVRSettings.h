#pragma once
/*
 *      Copyright (C) 2015-present Team Kodi
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

#include <map>
#include <string>
#include <utility>

#include "settings/lib/ISettingCallback.h"
#include "settings/lib/ISettingsHandler.h"
#include "settings/lib/Setting.h"

namespace PVR
{
  class CPVRSettings : private ISettingsHandler, private ISettingCallback
  {
  public:
    explicit CPVRSettings(const std::set<std::string> & settingNames);
    ~CPVRSettings() override;

    // ISettingsHandler implementation
    void OnSettingsLoaded() override;

    // ISettingCallback implementation
    void OnSettingChanged(std::shared_ptr<const CSetting> setting) override;

    bool GetBoolValue(const std::string &settingName) const;
    int GetIntValue(const std::string &settingName) const;
    std::string GetStringValue(const std::string &settingName) const;

    // settings value filler for start/end recording margin time for PVR timers.
    static void MarginTimeFiller(
      std::shared_ptr<const CSetting> setting, std::vector< std::pair<std::string, int> > &list, int &current, void *data);

    // Dynamically hide or show settings.
    static bool IsSettingVisible(const std::string &condition, const std::string &value, std::shared_ptr<const CSetting> setting, void *data);

  private:
    CPVRSettings(const CPVRSettings&) = delete;
    CPVRSettings& operator=(CPVRSettings const&) = delete;

    void Init(const std::set<std::string> &settingNames);

    CCriticalSection m_critSection;
    std::map<std::string, std::shared_ptr<CSetting>> m_settings;
  };
}
