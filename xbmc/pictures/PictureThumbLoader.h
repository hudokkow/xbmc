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

#include "utils/JobManager.h"
#include "ThumbLoader.h"

class CPictureThumbLoader : public CThumbLoader, public CJobQueue
{
public:
  CPictureThumbLoader();
  ~CPictureThumbLoader() override;

  bool LoadItem(CFileItem* pItem) override;
  bool LoadItemCached(CFileItem* pItem) override;
  bool LoadItemLookup(CFileItem* pItem) override;
  void SetRegenerateThumbs(bool regenerate) { m_regenerateThumbs = regenerate; };
  static void ProcessFoldersAndArchives(CFileItem *pItem);

  /*!
   \brief Callback from CThumbExtractor on completion of a generated image

   Performs the callbacks and updates the GUI.

   \sa CImageLoader, IJobCallback
   */
  void OnJobComplete(unsigned int jobID, bool success, CJob *job) override;

protected:
  void OnLoaderFinish() override;

private:
  bool m_regenerateThumbs;
};
