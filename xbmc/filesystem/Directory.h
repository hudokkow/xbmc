#pragma once
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

#include "IDirectory.h"
#include <memory>
#include <string>

namespace XFILE
{
/*!
 \ingroup filesystem
 \brief Wrappers for \e IDirectory
 */
class CDirectory
{
public:
  CDirectory(void);
  virtual ~CDirectory(void);

  class CHints
  {
  public:
    CHints() : flags(DIR_FLAG_DEFAULTS)
    {
    };
    std::string mask;
    int flags;
  };

  static bool GetDirectory(const CURL& url
                           , CFileItemList &items
                           , const std::string &strMask
                           , int flags);

  static bool GetDirectory(const CURL& url,
                           std::shared_ptr<IDirectory> pDirectory,
                           CFileItemList &items,
                           const CHints &hints);

  static bool GetDirectory(const CURL& url
                           , CFileItemList &items
                           , const CHints &hints);

  static bool Create(const CURL& url);
  static bool Exists(const CURL& url, bool bUseCache = true);
  static bool Remove(const CURL& url);
  static bool RemoveRecursive(const CURL& url);

  static bool GetDirectory(const std::string& strPath
                           , CFileItemList &items
                           , const std::string &strMask
                           , int flags);

  static bool GetDirectory(const std::string& strPath,
                           std::shared_ptr<IDirectory> pDirectory,
                           CFileItemList &items,
                           const std::string &strMask,
                           int flags);

  static bool GetDirectory(const std::string& strPath
                           , CFileItemList &items
                           , const CHints &hints);

  static bool Create(const std::string& strPath);
  static bool Exists(const std::string& strPath, bool bUseCache = true);
  static bool Remove(const std::string& strPath);
  static bool RemoveRecursive(const std::string& strPath);

  /*! \brief Filter files that act like directories from the list, replacing them with their directory counterparts
   \param items The item list to filter
   \param mask  The mask to apply when filtering files
   \param expandImages True to include disc images in file directory expansion
  */
  static void FilterFileDirectories(CFileItemList &items, const std::string &mask,
                                    bool expandImages=false);
};
}
