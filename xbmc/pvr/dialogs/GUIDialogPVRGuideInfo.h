#pragma once
/*
 *      Copyright (C) 2012-present Team Kodi
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

#include "pvr/PVRTypes.h"

namespace PVR
{
  class CGUIDialogPVRGuideInfo : public CGUIDialog
  {
  public:
    CGUIDialogPVRGuideInfo(void);
    ~CGUIDialogPVRGuideInfo(void) override;
    bool OnMessage(CGUIMessage& message) override;
    bool OnInfo(int actionID) override;
    bool HasListItems() const override { return true; }
    CFileItemPtr GetCurrentListItem(int offset = 0) override;

    void SetProgInfo(const CPVREpgInfoTagPtr &tag);

    static void ShowFor(const CFileItemPtr& item);

  protected:
    void OnInitWindow() override;

  private:
    bool OnClickButtonOK(CGUIMessage &message);
    bool OnClickButtonRecord(CGUIMessage &message);
    bool OnClickButtonPlay(CGUIMessage &message);
    bool OnClickButtonFind(CGUIMessage &message);
    bool OnClickButtonAddTimer(CGUIMessage &message);

    CPVREpgInfoTagPtr m_progItem;
  };
}
