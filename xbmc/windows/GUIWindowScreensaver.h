#pragma once

/*
 *      Copyright (C) 2005-present Team Kodi
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

#include "guilib/GUIWindow.h"

namespace ADDON { class CScreenSaver; }

class CGUIWindowScreensaver : public CGUIWindow
{
public:
  CGUIWindowScreensaver(void);

  bool OnMessage(CGUIMessage& message) override;
  bool OnAction(const CAction &action) override { return false; } // We're just a screen saver, nothing to do here
  void Render() override;
  void Process(unsigned int currentTime, CDirtyRegionList &regions) override;

protected:
  EVENT_RESULT OnMouseEvent(const CPoint &point, const CMouseEvent &event) override;

private:
  ADDON::CScreenSaver* m_addon;
};

