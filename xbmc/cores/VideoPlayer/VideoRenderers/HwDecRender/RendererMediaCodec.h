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

class CRendererMediaCodec : public CLinuxRendererGLES
{
public:
  CRendererMediaCodec();
  virtual ~CRendererMediaCodec();

  // Registration
  static CBaseRenderer* Create(CVideoBuffer *buffer);
  static bool Register();

  // Player functions
  virtual void AddVideoPicture(const VideoPicture &picture, int index, double currentClock) override;
  virtual void ReleaseBuffer(int idx) override;

  // Feature support
  virtual CRenderInfo GetRenderInfo() override;

protected:
  // textures
  virtual bool UploadTexture(int index) override;
  virtual void DeleteTexture(int index) override;
  virtual bool CreateTexture(int index) override;

  // hooks for hw dec renderer
  virtual bool LoadShadersHook() override;
  virtual bool RenderHook(int index) override;

private:
  float m_textureMatrix[16];
};
