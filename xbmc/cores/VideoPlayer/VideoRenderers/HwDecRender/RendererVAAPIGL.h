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

#include <memory>

#include "cores/VideoPlayer/VideoRenderers/LinuxRendererGL.h"
#include "VaapiEGL.h"

namespace VAAPI
{
class IVaapiWinSystem;
}

class CRendererVAAPI : public CLinuxRendererGL
{
public:
  CRendererVAAPI();
  ~CRendererVAAPI() override;

  static CBaseRenderer* Create(CVideoBuffer *buffer);
  static void Register(VAAPI::IVaapiWinSystem *winSystem, VADisplay vaDpy, EGLDisplay eglDisplay, bool &general, bool &deepColor);

  bool Configure(const VideoPicture &picture, float fps, unsigned int orientation) override;

  // Player functions
  bool ConfigChanged(const VideoPicture &picture) override;
  void ReleaseBuffer(int idx) override;
  bool NeedBuffer(int idx) override;

  // Feature support
  bool Supports(ERENDERFEATURE feature) override;
  bool Supports(ESCALINGMETHOD method) override;

protected:
  bool LoadShadersHook() override;
  bool RenderHook(int idx) override;
  void AfterRenderHook(int idx) override;

  // textures
  bool UploadTexture(int index) override;
  void DeleteTexture(int index) override;
  bool CreateTexture(int index) override;

  EShaderFormat GetShaderFormat() override;

  bool m_isVAAPIBuffer = true;
  std::unique_ptr<VAAPI::CVaapiTexture> m_vaapiTextures[NUM_BUFFERS];
  GLsync m_fences[NUM_BUFFERS];
  static VAAPI::IVaapiWinSystem *m_pWinSystem;
};
