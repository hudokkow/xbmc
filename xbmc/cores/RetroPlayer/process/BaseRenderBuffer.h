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
#pragma once

#include "IRenderBuffer.h"

#include <atomic>
#include <memory>

namespace KODI
{
namespace RETRO
{
  class CBaseRenderBuffer : public IRenderBuffer
  {
  public:
    CBaseRenderBuffer();
    ~CBaseRenderBuffer() override = default;

    // Partial implementation of IRenderBuffer
    void Acquire() override;
    void Acquire(std::shared_ptr<IRenderBufferPool> pool) override;
    void Release() override;
    IRenderBufferPool *GetPool() override { return m_pool.get(); }

  protected:
    // Reference counting
    std::atomic_int m_refCount;

    // Pool callback
    std::shared_ptr<IRenderBufferPool> m_pool;
  };
}
}
