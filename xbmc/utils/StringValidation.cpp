/*
 *      Copyright (C) 2013-present Team Kodi
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

#include "StringValidation.h"
#include "utils/StringUtils.h"

bool StringValidation::IsInteger(const std::string &input, void *data)
{
  return StringUtils::IsInteger(input);
}

bool StringValidation::IsPositiveInteger(const std::string &input, void *data)
{
  return StringUtils::IsNaturalNumber(input);
}

bool StringValidation::IsTime(const std::string &input, void *data)
{
  std::string strTime = input;
  StringUtils::Trim(strTime);

  if (StringUtils::EndsWithNoCase(strTime, " min"))
  {
    strTime = StringUtils::Left(strTime, strTime.size() - 4);
    StringUtils::TrimRight(strTime);

    return IsPositiveInteger(strTime, NULL);
  }
  else
  {
    // support [[HH:]MM:]SS
    std::vector<std::string> bits = StringUtils::Split(input, ":");
    if (bits.size() > 3)
      return false;

    for (std::vector<std::string>::const_iterator i = bits.begin(); i != bits.end(); ++i)
      if (!IsPositiveInteger(*i, NULL))
        return false;

    return true;
  }
  return false;
}
