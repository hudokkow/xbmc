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

#include "guilib/GUIDialog.h"

class CGUIDialogButtonMenu :
      public CGUIDialog
{
public:
  CGUIDialogButtonMenu(int id = WINDOW_DIALOG_BUTTON_MENU, const std::string &xmlFile = "DialogButtonMenu.xml");
  ~CGUIDialogButtonMenu(void) override;
  bool OnMessage(CGUIMessage &message) override;
  void FrameMove() override;
};
