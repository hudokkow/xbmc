/*
 *      Copyright (C) 2005-present Team Kodi
 *      http://xbmc.org
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

#include "guilib/Texture.h"
#include "WinSystemOSXGL.h"
#include "rendering/gl/RenderSystemGL.h"


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
std::unique_ptr<CWinSystemBase> CWinSystemBase::CreateWinSystem()
{
  std::unique_ptr<CWinSystemBase> winSystem(new CWinSystemOSXGL());
  return winSystem;
}

CWinSystemOSXGL::CWinSystemOSXGL()
{
}

CWinSystemOSXGL::~CWinSystemOSXGL()
{
}

void CWinSystemOSXGL::PresentRenderImpl(bool rendered)
{
  if (rendered)
    FlushBuffer();

  // FlushBuffer does not block if window is obscured
  // in this case we need to throttle the render loop
  if (IsObscured())
    usleep(10000);

  if (m_delayDispReset && m_dispResetTimer.IsTimePast())
  {
    m_delayDispReset = false;
    AnnounceOnResetDevice();
  }
}

void CWinSystemOSXGL::SetVSyncImpl(bool enable)
{
  EnableVSync(false);

  if (enable)
  {
    EnableVSync(true);
  }
}

bool CWinSystemOSXGL::ResizeWindow(int newWidth, int newHeight, int newLeft, int newTop)
{
  CWinSystemOSX::ResizeWindow(newWidth, newHeight, newLeft, newTop);
  CRenderSystemGL::ResetRenderSystem(newWidth, newHeight);

  if (m_bVSync)
  {
    EnableVSync(m_bVSync);
  }

  return true;
}

bool CWinSystemOSXGL::SetFullScreen(bool fullScreen, RESOLUTION_INFO& res, bool blankOtherDisplays)
{
  CWinSystemOSX::SetFullScreen(fullScreen, res, blankOtherDisplays);
  CRenderSystemGL::ResetRenderSystem(res.iWidth, res.iHeight);

  if (m_bVSync)
  {
    EnableVSync(m_bVSync);
  }

  return true;
}

