#pragma once
/*
 *      Copyright (C) 2012-present Team Kodi
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

#include "filesystem/IFileDirectory.h"

namespace XFILE
{
  class CAPKDirectory : public IFileDirectory
  {
    public:
    CAPKDirectory() {};
    virtual ~CAPKDirectory() {};
    virtual bool GetDirectory(const CURL& url, CFileItemList &items);
    virtual bool ContainsFiles(const CURL& url);
    virtual DIR_CACHE_TYPE GetCacheType(const CURL& url) const;
    virtual bool Exists(const CURL& url);
  };
}
