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

#pragma once

#include "settings/lib/ISettingCallback.h"
#include "threads/CriticalSection.h"
#include <atomic>
#include <memory>
#include <string>
#include <vector>

class CSetting;
class CAEStreamInfo;

namespace ActiveAE
{
class CActiveAE;

class CActiveAESettings : public ISettingCallback
{
public:
  CActiveAESettings(CActiveAE &ae);
  virtual ~CActiveAESettings();

  void OnSettingChanged(std::shared_ptr<const CSetting> setting) override;

  static void SettingOptionsAudioDevicesFiller(std::shared_ptr<const CSetting> setting,
                                               std::vector< std::pair<std::string, std::string> > &list,
                                               std::string &current, void *data);
  static void SettingOptionsAudioDevicesPassthroughFiller(std::shared_ptr<const CSetting> setting,
                                                          std::vector< std::pair<std::string, std::string> > &list,
                                                          std::string &current, void *data);
  static void SettingOptionsAudioQualityLevelsFiller(std::shared_ptr<const CSetting> setting,
                                                     std::vector< std::pair<std::string, int> > &list, int &current, void *data);
  static void SettingOptionsAudioStreamsilenceFiller(std::shared_ptr<const CSetting> setting,
                                                     std::vector< std::pair<std::string, int> > &list, int &current, void *data);
  static bool IsSettingVisible(const std::string &condition, const std::string &value,
                               std::shared_ptr<const CSetting> setting, void *data);

protected:
  static void SettingOptionsAudioDevicesFillerGeneral(std::shared_ptr<const CSetting> setting, std::vector< std::pair<std::string, std::string> > &list, std::string &current, bool passthrough);

  CActiveAE &m_audioEngine;
  CCriticalSection m_cs;
  static CActiveAESettings* m_instance;
};
};
