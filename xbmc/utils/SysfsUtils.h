#pragma once
/*
 *      Copyright (C) 2011-present Team Kodi
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

#include <string>

class SysfsUtils
{
public:
  static int SetString(const std::string& path, const std::string& valstr);
  static int GetString(const std::string& path, std::string& valstr);
  static int SetInt(const std::string& path, const int val);
  static int GetInt(const std::string& path, int& val);
  static bool Has(const std::string& path);
  static bool HasRW(const std::string &path);
};
