#pragma once
/*
 *      Copyright (C) 2016-present Team Kodi
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

#include "pvr/PVRTypes.h"

class CFileItem;
typedef std::shared_ptr<CFileItem> CFileItemPtr;

namespace PVR
{
  class CPVRItem
  {
  public:
    explicit CPVRItem(const CFileItemPtr &item) : m_item(item.get()) {}
    explicit CPVRItem(const CFileItem *item) : m_item(item) {}

    CPVREpgInfoTagPtr GetEpgInfoTag() const;
    CPVREpgInfoTagPtr GetNextEpgInfoTag() const;
    CPVRChannelPtr GetChannel() const;
    CPVRTimerInfoTagPtr GetTimerInfoTag() const;
    CPVRRecordingPtr GetRecording() const;

    bool IsRadio() const;

  private:
    const CFileItem* m_item;
  };

} // namespace PVR
