/*
 *      Copyright (C) 2016-present Team Kodi
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

#include "InfoScanner.h"
#include "URL.h"
#include "Util.h"
#include "filesystem/File.h"
#include "utils/log.h"
#include "utils/URIUtils.h"

bool CInfoScanner::HasNoMedia(const std::string &strDirectory) const
{
  std::string noMediaFile = URIUtils::AddFileToFolder(strDirectory, ".nomedia");
  return XFILE::CFile::Exists(noMediaFile);
}

bool CInfoScanner::IsExcluded(const std::string& strDirectory, const std::vector<std::string> &regexps)
{
  if (CUtil::ExcludeFileOrFolder(strDirectory, regexps))
    return true;

  if (!URIUtils::IsPlugin(strDirectory) && HasNoMedia(strDirectory))
  {
    CLog::Log(LOGWARNING, "Skipping item '%s' with '.nomedia' file in parent directory, it won't be added to the library.", CURL::GetRedacted(strDirectory).c_str());
    return true;
  }
  return false;
}
