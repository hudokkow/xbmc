#pragma once
/*
 *      Copyright (C) 2015-present Team Kodi
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

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "input/KeyboardLayout.h"

class CSetting;

typedef std::map<std::string, CKeyboardLayout> KeyboardLayouts;

class CKeyboardLayoutManager
{
public:
  virtual ~CKeyboardLayoutManager();

  static CKeyboardLayoutManager& GetInstance();

  bool Load(const std::string& path = "");
  void Unload();

  const KeyboardLayouts& GetLayouts() const { return m_layouts; }
  bool GetLayout(const std::string& name, CKeyboardLayout& layout) const;

  static void SettingOptionsKeyboardLayoutsFiller(std::shared_ptr<const CSetting> setting, std::vector< std::pair<std::string, std::string> > &list, std::string &current, void* data);

private:
  CKeyboardLayoutManager() = default;
  CKeyboardLayoutManager(const CKeyboardLayoutManager&) = delete;
  CKeyboardLayoutManager const& operator=(CKeyboardLayoutManager const&) = delete;

  KeyboardLayouts m_layouts;
};
