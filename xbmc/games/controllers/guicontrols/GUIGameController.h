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
#pragma once

#include "games/controllers/ControllerTypes.h"
#include "guilib/GUIImage.h"
#include "threads/CriticalSection.h"

namespace KODI
{
namespace GAME
{
  class CGUIGameController : public CGUIImage
  {
  public:
    CGUIGameController(int parentID, int controlID, float posX, float posY, float width, float height);
    CGUIGameController(const CGUIGameController &from);

    virtual ~CGUIGameController() = default;

    // implementation of CGUIControl via CGUIImage
    virtual CGUIGameController* Clone(void) const override;
    virtual void Render(void) override;

    void ActivateController(const ControllerPtr& controller);

  private:
    ControllerPtr       m_currentController;
    CCriticalSection    m_mutex;
  };
}
}
