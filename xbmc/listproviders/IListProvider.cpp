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

#include "IListProvider.h"
#include "utils/XBMCTinyXML.h"
#include "StaticProvider.h"
#include "DirectoryProvider.h"
#include "MultiProvider.h"

IListProvider *IListProvider::Create(const TiXmlNode *node, int parentID)
{
  const TiXmlNode *root = node->FirstChild("content");
  if (root)
  {
    const TiXmlNode *next = root->NextSibling("content");
    if (next)
      return new CMultiProvider(root, parentID);

    return CreateSingle(root, parentID);
  }
  return NULL;
}

IListProvider *IListProvider::CreateSingle(const TiXmlNode *content, int parentID)
{
  const TiXmlElement *item = content->FirstChildElement("item");
  if (item)
    return new CStaticListProvider(content->ToElement(), parentID);

  if (!content->NoChildren())
    return new CDirectoryProvider(content->ToElement(), parentID);

  return NULL;
}
