/*
 *      Copyright (C) 2007-present Team Kodi
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

#include "cores/VideoPlayer/VideoRenderers/LinuxRendererGLES.h"
#include <CoreVideo/CVOpenGLESTextureCache.h>

class CRendererVTB : public CLinuxRendererGLES
{
public:
  CRendererVTB();
  virtual ~CRendererVTB();

  static CBaseRenderer* Create(CVideoBuffer *buffer);
  static bool Register();

  // Player functions
  void ReleaseBuffer(int idx) override;
  bool NeedBuffer(int idx) override;

protected:
  // hooks for hw dec renderer
  bool LoadShadersHook() override;
  void AfterRenderHook(int idx) override;
  EShaderFormat GetShaderFormat() override;

  // textures
  bool UploadTexture(int index) override;
  void DeleteTexture(int index) override;
  bool CreateTexture(int index) override;

  CVOpenGLESTextureCacheRef m_textureCache;
  struct CRenderBuffer
  {
    CVOpenGLESTextureRef m_textureY;
    CVOpenGLESTextureRef m_textureUV;
    CVBufferRef m_videoBuffer;
    GLsync m_fence;
  };
  CRenderBuffer m_vtbBuffers[NUM_BUFFERS];
  CVEAGLContext m_glContext;
};

