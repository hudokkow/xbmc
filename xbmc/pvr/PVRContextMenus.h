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
#include <vector>

class IContextMenuItem;

namespace PVR
{
  class CPVRContextMenuManager
  {
  public:
    static CPVRContextMenuManager& GetInstance();

    std::vector<std::shared_ptr<IContextMenuItem>> GetMenuItems() const { return m_items; }

  private:
    CPVRContextMenuManager();
    CPVRContextMenuManager(const CPVRContextMenuManager&) = delete;
    CPVRContextMenuManager const& operator=(CPVRContextMenuManager const&) = delete;
    virtual ~CPVRContextMenuManager() = default;

    std::vector<std::shared_ptr<IContextMenuItem>> m_items;
  };

} // namespace PVR
