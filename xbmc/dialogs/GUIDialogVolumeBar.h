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
#include "threads/CriticalSection.h"

#include <set>

class IGUIVolumeBarCallback;

class CGUIDialogVolumeBar : public CGUIDialog
{
public:
  CGUIDialogVolumeBar(void);
  ~CGUIDialogVolumeBar(void) override;
  bool OnMessage(CGUIMessage& message) override;
  bool OnAction(const CAction &action) override;

  // Volume bar interface
  void RegisterCallback(IGUIVolumeBarCallback *callback);
  void UnregisterCallback(IGUIVolumeBarCallback *callback);
  bool IsVolumeBarEnabled() const;

private:
  std::set<IGUIVolumeBarCallback*> m_callbacks;
  CCriticalSection m_callbackMutex;
};
