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

#pragma once

#include <string>
#include <stdint.h>

class Crc32
{
public:
  Crc32();
  void Reset();
  void Compute(const char* buffer, size_t count);
  static uint32_t Compute(const std::string& strValue);
  static uint32_t ComputeFromLowerCase(const std::string& strValue);

  operator uint32_t () const
  {
    return m_crc;
  }

private:
  uint32_t m_crc;
};

