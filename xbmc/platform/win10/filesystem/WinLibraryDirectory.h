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
#pragma once

#include "filesystem/IDirectory.h"

namespace XFILE
{
  class CWinLibraryFile;

  class CWinLibraryDirectory : public IDirectory
  {
  public:
    CWinLibraryDirectory();
    virtual ~CWinLibraryDirectory(void);
    bool GetDirectory(const CURL& url, CFileItemList &items) override;
    DIR_CACHE_TYPE GetCacheType(const CURL& url) const override { return DIR_CACHE_ONCE; };
    bool Create(const CURL& url) override;
    bool Exists(const CURL& url) override;
    bool Remove(const CURL& url) override;

    static bool GetStoragePath(std::string library, std::string& path);
    static bool IsValid(const CURL& url);

  private:
    friend CWinLibraryFile;
    static winrt::Windows::Storage::StorageFolder GetRootFolder(const CURL& url);
    static winrt::Windows::Storage::StorageFolder GetFolder(const CURL &url);
  };
}
