/*
 *      Copyright (C) 2017-present Team Kodi
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
#pragma once

#include "guilib/GUIControl.h"
#include "guilib/guiinfo/GUIInfoTypes.h"

#include <memory>

namespace KODI
{
namespace RETRO
{
class CGUIRenderSettings;
class CGUIRenderHandle;
class IGUIRenderSettings;

class CGUIGameControl : public CGUIControl
{
public:
  CGUIGameControl(int parentID, int controlID, float posX, float posY, float width, float height);
  CGUIGameControl(const CGUIGameControl &other);
  ~CGUIGameControl() override;

  // GUI functions
  void SetScalingMethod(const KODI::GUILIB::GUIINFO::CGUIInfoLabel &scalingMethod);
  void SetViewMode(const KODI::GUILIB::GUIINFO::CGUIInfoLabel &viewMode);

  // Rendering functions
  bool HasScalingMethod() const { return m_bHasScalingMethod; }
  bool HasViewMode() const { return m_bHasViewMode; }
  IGUIRenderSettings *GetRenderSettings() const;

  // implementation of CGUIControl
  CGUIGameControl *Clone() const override { return new CGUIGameControl(*this); };
  void Process(unsigned int currentTime, CDirtyRegionList &dirtyregions) override;
  void Render() override;
  void RenderEx() override;
  bool CanFocus() const override;
  void SetPosition(float posX, float posY) override;
  void SetWidth(float width) override;
  void SetHeight(float height) override;
  void UpdateInfo(const CGUIListItem *item = nullptr) override;

private:
  void Reset();

  void RegisterControl();
  void UnregisterControl();

  // GUI properties
  KODI::GUILIB::GUIINFO::CGUIInfoLabel m_scalingMethodInfo;
  KODI::GUILIB::GUIINFO::CGUIInfoLabel m_viewModeInfo;

  // Rendering properties
  bool m_bHasScalingMethod = false;
  bool m_bHasViewMode = false;
  std::unique_ptr<CGUIRenderSettings> m_renderSettings;
  std::shared_ptr<CGUIRenderHandle> m_renderHandle;
};

}
}
