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

#include "ProcessInfoWin10.h"
#include "cores/VideoPlayer/Process/ProcessInfo.h"
#include "rendering/dx/RenderContext.h"
#include <set>

using namespace VIDEOPLAYER;

CProcessInfo* CProcessInfoWin10::Create()
{
  return new CProcessInfoWin10();
}

void CProcessInfoWin10::Register()
{
  CProcessInfo::RegisterProcessControl("win10", CProcessInfoWin10::Create);
}

EINTERLACEMETHOD CProcessInfoWin10::GetFallbackDeintMethod()
{
  return EINTERLACEMETHOD::VS_INTERLACEMETHOD_AUTO;
}

std::vector<AVPixelFormat> CProcessInfoWin10::GetRenderFormats()
{
  auto processor = DX::Windowing()->m_processorFormats;
  auto shaders = DX::Windowing()->m_shaderFormats;

  std::set<AVPixelFormat> formats;
  formats.insert(processor.begin(), processor.end());
  formats.insert(shaders.begin(), shaders.end());

  return std::vector<AVPixelFormat>(formats.begin(), formats.end());
}
