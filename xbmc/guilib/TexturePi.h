/*
 *      Copyright (C) 2013-present Team Kodi
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

#include "TextureGL.h"

#include "system_gl.h"

/************************************************************************/
/*    CGLTexture                                                       */
/************************************************************************/
class CPiTexture : public CGLTexture
{
public:
  CPiTexture(unsigned int width = 0, unsigned int height = 0, unsigned int format = XB_FMT_A8R8G8B8);
  virtual ~CPiTexture();
  void CreateTextureObject();
  void LoadToGPU();
  void Update(unsigned int width, unsigned int height, unsigned int pitch, unsigned int format, const unsigned char *pixels, bool loadToGPU);
  void Allocate(unsigned int width, unsigned int height, unsigned int format);
  bool LoadFromFileInternal(const std::string& texturePath, unsigned int maxWidth, unsigned int maxHeight, bool requirePixels, const std::string& strMimeType = "");

protected:

private:
  void *m_egl_image;
};
