#pragma once
/*
 *      Copyright (C) 2013-present Team Kodi
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

#include <string>

class TiXmlNode;

class ISettingControl
{
public:
  ISettingControl() = default;
  virtual ~ISettingControl() = default;

  virtual std::string GetType() const = 0;
  const std::string& GetFormat() const { return m_format; }
  bool GetDelayed() const { return m_delayed; }
  void SetDelayed(bool delayed) { m_delayed = delayed; }

  virtual bool Deserialize(const TiXmlNode *node, bool update = false);
  virtual bool SetFormat(const std::string &format) { return true; }

protected:
  bool m_delayed = false;
  std::string m_format;
};
