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
#include "video/Teletext.h"

class CBaseTexture;

class CGUIDialogTeletext : public CGUIDialog
{
public:
  CGUIDialogTeletext(void);
  ~CGUIDialogTeletext(void) override;
  bool OnMessage(CGUIMessage& message) override;
  bool OnAction(const CAction& action) override;
  bool OnBack(int actionID) override;
  void Process(unsigned int currentTime, CDirtyRegionList &dirtyregions) override;
  void Render() override;
  void OnInitWindow() override;
  void OnDeinitWindow(int nextWindowID) override;

protected:
  bool                m_bClose;           /* Close sendet, needed for fade out */
  CBaseTexture*       m_pTxtTexture;      /* Texture info class to render to screen */
  CRect               m_vertCoords;       /* Coordinates of teletext field on screen */
  CTeletextDecoder    m_TextDecoder;      /* Decoding class for teletext code */

private:
  void SetCoordinates();
};
