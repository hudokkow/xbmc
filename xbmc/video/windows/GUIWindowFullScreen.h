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

class CGUIDialog;

class CGUIWindowFullScreen : public CGUIWindow
{
public:
  CGUIWindowFullScreen();
  ~CGUIWindowFullScreen(void) override;
  bool OnMessage(CGUIMessage& message) override;
  bool OnAction(const CAction &action) override;
  void ClearBackground() override;
  void FrameMove() override;
  void Process(unsigned int currentTime, CDirtyRegionList &dirtyregion) override;
  void Render() override;
  void RenderEx() override;
  void OnWindowLoaded() override;
  bool HasVisibleControls() override;

protected:
  EVENT_RESULT OnMouseEvent(const CPoint &point, const CMouseEvent &event) override;

private:
  void SeekChapter(int iChapter);
  void ToggleOSD();
  void TriggerOSD();
  CGUIDialog *GetOSD();

  bool m_viewModeChanged;
  unsigned int m_dwShowViewModeTimeout;

  bool m_bShowCurrentTime;
};
