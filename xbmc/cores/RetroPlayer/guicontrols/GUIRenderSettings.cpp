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

#include "GUIRenderSettings.h"
#include "GUIGameControl.h"
#include "threads/SingleLock.h"

using namespace KODI;
using namespace RETRO;

CGUIRenderSettings::CGUIRenderSettings(CGUIGameControl &guiControl) :
  m_guiControl(guiControl)
{
}

bool CGUIRenderSettings::HasScalingMethod() const
{
  return m_guiControl.HasScalingMethod();
}

bool CGUIRenderSettings::HasViewMode() const
{
  return m_guiControl.HasViewMode();
}

CRenderSettings CGUIRenderSettings::GetSettings() const
{
  CSingleLock lock(m_mutex);

  return m_renderSettings;
}

void CGUIRenderSettings::Reset()
{
  CSingleLock lock(m_mutex);

  return m_renderSettings.Reset();
}

void CGUIRenderSettings::SetSettings(CRenderSettings settings)
{
  CSingleLock lock(m_mutex);

  m_renderSettings = std::move(settings);
}

void CGUIRenderSettings::SetGeometry(CRenderGeometry geometry)
{
  CSingleLock lock(m_mutex);

  m_renderSettings.Geometry() = std::move(geometry);
}

void CGUIRenderSettings::SetScalingMethod(ESCALINGMETHOD scalingMethod)
{
  CSingleLock lock(m_mutex);

  m_renderSettings.VideoSettings().SetScalingMethod(scalingMethod);
}

void CGUIRenderSettings::SetViewMode(ViewMode viewMode)
{
  CSingleLock lock(m_mutex);

  m_renderSettings.VideoSettings().SetRenderViewMode(viewMode);
}
