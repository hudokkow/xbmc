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

#include "OverrideDirectory.h"
#include "URL.h"
#include "filesystem/Directory.h"

using namespace XFILE;


COverrideDirectory::COverrideDirectory() = default;


COverrideDirectory::~COverrideDirectory() = default;

bool COverrideDirectory::Create(const CURL& url)
{
  std::string translatedPath = TranslatePath(url);

  return CDirectory::Create(translatedPath.c_str());
}

bool COverrideDirectory::Remove(const CURL& url)
{
  std::string translatedPath = TranslatePath(url);

  return CDirectory::Remove(translatedPath.c_str());
}

bool COverrideDirectory::Exists(const CURL& url)
{
  std::string translatedPath = TranslatePath(url);

  return CDirectory::Exists(translatedPath.c_str());
}
