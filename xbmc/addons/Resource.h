#pragma once
/*
 *      Copyright (C) 2014-present Team Kodi
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

#include <memory>

#include "addons/Addon.h"
#include "utils/URIUtils.h"

namespace ADDON
{

class CResource : public CAddon
{
public:
  ~CResource() override = default;

  virtual bool IsAllowed(const std::string &file) const = 0;

  virtual std::string GetFullPath(const std::string &filePath) const
  {
    return URIUtils::AddFileToFolder(GetResourcePath(), filePath);
  }

protected:
  explicit CResource(CAddonInfo addonInfo) : CAddon(std::move(addonInfo)) {}

  std::string GetResourcePath() const
  {
    return URIUtils::AddFileToFolder(Path(), "resources");
  }
};

}
