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

#include <vector>
#include "storage/IStorageProvider.h"

class CLinuxStorageProvider : public IStorageProvider
{
public:
  CLinuxStorageProvider();
  virtual ~CLinuxStorageProvider();

  void Initialize() override;
  void Stop() override;
  void GetLocalDrives(VECSOURCES &localDrives) override;
  void GetRemovableDrives(VECSOURCES &removableDrives) override;
  bool Eject(const std::string& mountpath) override;
  std::vector<std::string> GetDiskUsage() override;
  bool PumpDriveChangeEvents(IStorageEventsCallback *callback) override;

private:
  IStorageProvider *m_instance;
};
