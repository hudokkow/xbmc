#pragma once
/*
 *      Copyright (C) 2005-present Team Kodi
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

#include "IFileDirectory.h"
#include <string>

class CSmartPlaylist;

namespace XFILE
{
  class CSmartPlaylistDirectory : public IFileDirectory
  {
  public:
    CSmartPlaylistDirectory();
    ~CSmartPlaylistDirectory() override;
    bool GetDirectory(const CURL& url, CFileItemList& items) override;
    bool AllowAll() const override { return true; }
    bool ContainsFiles(const CURL& url) override;
    bool Remove(const CURL& url) override;

    static bool GetDirectory(const CSmartPlaylist &playlist, CFileItemList& items, const std::string &strBaseDir = "", bool filter = false);

    static std::string GetPlaylistByName(const std::string& name, const std::string& playlistType);
  };
}
