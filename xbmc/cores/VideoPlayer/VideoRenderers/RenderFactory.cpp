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

#include "RenderFactory.h"
#include "threads/SingleLock.h"

using namespace VIDEOPLAYER;

CCriticalSection renderSection;
std::map<std::string, VIDEOPLAYER::CreateRenderer> CRendererFactory::m_renderers;

CBaseRenderer* CRendererFactory::CreateRenderer(std::string id, CVideoBuffer *buffer)
{
  CSingleLock lock(renderSection);

  auto it = m_renderers.find(id);
  if (it != m_renderers.end())
  {
    return it->second(buffer);
  }

  return nullptr;
}

std::vector<std::string> CRendererFactory::GetRenderers()
{
  CSingleLock lock(renderSection);

  std::vector<std::string> ret;
  for (auto &renderer : m_renderers)
  {
    ret.push_back(renderer.first);
  }
  return ret;
}

void CRendererFactory::RegisterRenderer(std::string id, ::CreateRenderer createFunc)
{
  CSingleLock lock(renderSection);

  m_renderers[id] = createFunc;
}

void CRendererFactory::ClearRenderer()
{
  CSingleLock lock(renderSection);

  m_renderers.clear();
}
