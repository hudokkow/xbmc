#ifndef GUI_DIALOG_ACCESS_POINTS
#define GUI_DIALOG_ACCESS_POINTS

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

#pragma once

#include <vector>
#include "guilib/GUIDialog.h"
#include "Network.h"

class CFileItemList;

class CGUIDialogAccessPoints : public CGUIDialog
{
public:
  CGUIDialogAccessPoints(void);
  ~CGUIDialogAccessPoints(void) override;
  void OnInitWindow() override;
  bool OnAction(const CAction &action) override;
  void SetInterfaceName(std::string interfaceName);
  std::string GetSelectedAccessPointEssId();
  EncMode GetSelectedAccessPointEncMode();
  bool WasItemSelected();

private:
  std::vector<NetworkAccessPoint> m_aps;
  std::string m_interfaceName;
  std::string m_selectedAPEssId;
  EncMode m_selectedAPEncMode;
  bool m_wasItemSelected;
  CFileItemList *m_accessPoints;
};

#endif
