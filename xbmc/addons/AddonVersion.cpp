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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "AddonVersion.h"
#include "utils/log.h"
#include "utils/StringUtils.h"

namespace {
// Add-on versions are used e.g. in file names and should
// not have too much freedom in their accepted characters
// Things that should be allowed: e.g. 0.1.0~beta3+git010cab3
// Note that all of these characters are url-safe
const std::string VALID_ADDON_VERSION_CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.+_@~";
}

namespace ADDON
{
  AddonVersion::AddonVersion(const std::string& version)
  : mEpoch(0), mUpstream(version.empty() ? "0.0.0" : version)
  {
    size_t pos = mUpstream.find(':');
    if (pos != std::string::npos)
    {
      mEpoch = strtol(mUpstream.c_str(), NULL, 10);
      mUpstream.erase(0, pos+1);
    }

    pos = mUpstream.find('-');
    if (pos != std::string::npos)
    {
      mRevision = mUpstream.substr(pos+1);
      if (mRevision.find_first_not_of(VALID_ADDON_VERSION_CHARACTERS) != std::string::npos)
      {
        CLog::Log(LOGERROR, "AddonVersion: {} is not a valid revision number", mRevision);
        mRevision = "";
      }
      mUpstream.erase(pos);
    }

    if (mUpstream.find_first_not_of(VALID_ADDON_VERSION_CHARACTERS) != std::string::npos)
    {
      CLog::Log(LOGERROR, "AddonVersion: {} is not a valid version", mUpstream);
      mUpstream = "0.0.0";
    }
  }

  /**Compare two components of a Debian-style version.  Return -1, 0, or 1
   * if a is less than, equal to, or greater than b, respectively.
   */
  int AddonVersion::CompareComponent(const char *a, const char *b)
  {
    while (*a && *b)
    {
      while (*a && *b && !isdigit(*a) && !isdigit(*b))
      {
        if (*a != *b)
        {
          if (*a == '~') return -1;
          if (*b == '~') return 1;
          return *a < *b ? -1 : 1;
        }
        a++;
        b++;
      }
      if (*a && *b && (!isdigit(*a) || !isdigit(*b)))
      {
        if (*a == '~') return -1;
        if (*b == '~') return 1;
        return isdigit(*a) ? -1 : 1;
      }

      char *next_a, *next_b;
      long int num_a = strtol(a, &next_a, 10);
      long int num_b = strtol(b, &next_b, 10);
      if (num_a != num_b)
        return num_a < num_b ? -1 : 1;

      a = next_a;
      b = next_b;
    }
    if (!*a && !*b)
      return 0;
    if (*a)
      return *a == '~' ? -1 : 1;
    else
      return *b == '~' ? 1 : -1;
  }

  bool AddonVersion::operator<(const AddonVersion& other) const
  {
    if (mEpoch != other.mEpoch)
      return mEpoch < other.mEpoch;

    int result = CompareComponent(mUpstream.c_str(), other.mUpstream.c_str());
    if (result)
      return (result < 0);

    return (CompareComponent(mRevision.c_str(), other.mRevision.c_str()) < 0);
  }

  bool AddonVersion::operator>(const AddonVersion & other) const
  {
    return !(*this <= other);
  }

  bool AddonVersion::operator==(const AddonVersion& other) const
  {
    return mEpoch == other.mEpoch
      && CompareComponent(mUpstream.c_str(), other.mUpstream.c_str()) == 0
      && CompareComponent(mRevision.c_str(), other.mRevision.c_str()) == 0;
  }

  bool AddonVersion::operator!=(const AddonVersion & other) const
  {
    return !(*this == other);
  }

  bool AddonVersion::operator<=(const AddonVersion& other) const
  {
    return *this < other || *this == other;
  }

  bool AddonVersion::operator>=(const AddonVersion & other) const
  {
    return !(*this < other);
  }

  bool AddonVersion::empty() const
  {
    return mEpoch == 0 && mUpstream == "0.0.0" && mRevision.empty();
  }

  std::string AddonVersion::asString() const
  {
    std::string out;
    if (mEpoch)
      out = StringUtils::Format("%i:", mEpoch);
    out += mUpstream;
    if (!mRevision.empty())
      out += "-" + mRevision;
    return out;
  }

  bool AddonVersion::SplitFileName(std::string& ID, std::string& version,
                                   const std::string& filename)
  {
    size_t dpos = filename.rfind("-");
    if (dpos == std::string::npos)
      return false;
    ID = filename.substr(0, dpos);
    version = filename.substr(dpos + 1);
    version = version.substr(0, version.size() - 4);

    return true;
  }
}
