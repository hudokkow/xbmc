/*
 *      Copyright (C) 2017-present Team Kodi
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
#pragma once

class CKey;

namespace KODI
{
namespace KEYBOARD
{
  /*!
   * \brief Interface for translating keys to action IDs
   */
  class IActionMap
  {
  public:
    virtual ~IActionMap() = default;

    /*!
     * \brief Get the action ID mapped to the specified key
     *
     * \param key The key to look up
     *
     * \return The action ID from Action.h, or ACTION_NONE if no action is
     *         mapped to the specified key
     */
    virtual unsigned int GetActionID(const CKey& key) = 0;
  };
}
}
