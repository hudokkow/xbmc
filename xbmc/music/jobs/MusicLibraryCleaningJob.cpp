/*
 *      Copyright (C) 2017-present Team Kodi
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

#include "MusicLibraryCleaningJob.h"
#include "dialogs/GUIDialogProgress.h"
#include "music/MusicDatabase.h"

CMusicLibraryCleaningJob::CMusicLibraryCleaningJob(CGUIDialogProgress* progressDialog)
  : CMusicLibraryProgressJob(nullptr)
{ 
  if (progressDialog)
    SetProgressIndicators(nullptr, progressDialog);
  SetAutoClose(true);
}

CMusicLibraryCleaningJob::~CMusicLibraryCleaningJob() = default;

bool CMusicLibraryCleaningJob::operator==(const CJob* job) const
{
  if (strcmp(job->GetType(), GetType()) != 0)
    return false;

  const CMusicLibraryCleaningJob* cleaningJob = dynamic_cast<const CMusicLibraryCleaningJob*>(job);
  if (cleaningJob == nullptr)
    return false;

  return true;
}

bool CMusicLibraryCleaningJob::Work(CMusicDatabase &db)
{
  db.Cleanup(GetProgressDialog());
  return true;
}
