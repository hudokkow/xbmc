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

#include "PlayListURL.h"
#include "filesystem/File.h"
#include "utils/URIUtils.h"
#include "utils/StringUtils.h"

using namespace PLAYLIST;
using namespace XFILE;

// example url file
//[DEFAULT]
//BASEURL=http://msdn2.microsoft.com/en-us/library/ms812698.aspx
//[InternetShortcut]
//URL=http://msdn2.microsoft.com/en-us/library/ms812698.aspx

CPlayListURL::CPlayListURL(void) = default;

CPlayListURL::~CPlayListURL(void) = default;

bool CPlayListURL::Load(const std::string& strFileName)
{
  char szLine[4096];
  std::string strLine;

  Clear();

  m_strPlayListName = URIUtils::GetFileName(strFileName);
  URIUtils::GetParentPath(strFileName, m_strBasePath);

  CFile file;
  if (!file.Open(strFileName) )
  {
    file.Close();
    return false;
  }

  while (file.ReadString(szLine, 1024))
  {
    strLine = szLine;
    StringUtils::RemoveCRLF(strLine);

    if (StringUtils::StartsWith(strLine, "[InternetShortcut]"))
    {
      if (file.ReadString(szLine,1024))
      {
        strLine  = szLine;
        StringUtils::RemoveCRLF(strLine);
        if (StringUtils::StartsWith(strLine, "URL="))
        {
          CFileItemPtr newItem(new CFileItem(strLine.substr(4), false));
          Add(newItem);
        }
      }
    }
  }

  file.Close();
  return true;
}

