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

#include "GUIRenderTarget.h"
#include "cores/RetroPlayer/guicontrols/GUIGameControl.h"
#include "cores/RetroPlayer/guiwindows/GameWindowFullScreen.h"
#include "cores/RetroPlayer/rendering/IRenderManager.h"

using namespace KODI;
using namespace RETRO;

// --- CGUIRenderTarget --------------------------------------------------------

CGUIRenderTarget::CGUIRenderTarget(IRenderManager *renderManager) :
  m_renderManager(renderManager)
{
}

// --- CGUIRenderControl -------------------------------------------------------

CGUIRenderControl::CGUIRenderControl(IRenderManager *renderManager, CGUIGameControl &gameControl) :
  CGUIRenderTarget(renderManager),
  m_gameControl(gameControl)
{
}

void CGUIRenderControl::Render()
{
  m_renderManager->RenderControl(true, true, m_gameControl.GetRenderRegion(), m_gameControl.GetRenderSettings());
}

void CGUIRenderControl::RenderEx()
{
  //! @todo
  //m_renderManager->RenderControl(false, false, m_gameControl.GetRenderRegion(), m_gameControl.GetRenderSettings());
}

// --- CGUIRenderFullScreen ----------------------------------------------------

CGUIRenderFullScreen::CGUIRenderFullScreen(IRenderManager *renderManager, CGameWindowFullScreen &window) :
  CGUIRenderTarget(renderManager),
  m_window(window)
{
}

void CGUIRenderFullScreen::Render()
{
  m_renderManager->RenderWindow(true, m_window.GetCoordsRes());
}

void CGUIRenderFullScreen::RenderEx()
{
  //! @todo
  //m_renderManager->RenderWindow(false, m_window.GetCoordsRes());
}

void CGUIRenderFullScreen::ClearBackground()
{
  m_renderManager->ClearBackground();
}
