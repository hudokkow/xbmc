/*
 *      Copyright (C) 2017-present Team Kodi
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

#include "IButtonMapper.h"
#include "input/joysticks/JoystickTypes.h"

#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

class IWindowKeymap;
class TiXmlElement;
class TiXmlNode;

class CJoystickMapper : public IButtonMapper
{
public:
  CJoystickMapper() = default;
  virtual ~CJoystickMapper();

  // implementation of IButtonMapper
  virtual void MapActions(int windowID, const TiXmlNode *pDevice) override;
  virtual void Clear() override;

  std::vector<std::shared_ptr<const IWindowKeymap>> GetJoystickKeymaps() const;

private:
  void DeserializeJoystickNode(const TiXmlNode* pDevice, std::string &controllerId);
  bool DeserializeButton(const TiXmlElement *pButton, std::string &feature, KODI::JOYSTICK::ANALOG_STICK_DIRECTION &dir, unsigned int& holdtimeMs, std::set<std::string>& hotkeys, std::string &actionStr);

  using ControllerID = std::string;
  std::map<ControllerID, std::shared_ptr<IWindowKeymap>> m_joystickKeymaps;

  std::vector<std::string> m_controllerIds;
};
