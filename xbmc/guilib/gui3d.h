#pragma once

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

#include "PlatformDefs.h" // for TARGET_WINDOWS types

#define GAMMA_RAMP_FLAG  D3DSGR_CALIBRATE

#define D3DFMT_LIN_A8R8G8B8 D3DFMT_A8R8G8B8
#define D3DFMT_LIN_X8R8G8B8 D3DFMT_X8R8G8B8
#define D3DFMT_LIN_L8       D3DFMT_L8
#define D3DFMT_LIN_D16      D3DFMT_D16
#define D3DFMT_LIN_A8       D3DFMT_A8

#define D3DPIXELSHADERDEF DWORD

struct D3DTexture
{
  DWORD Common;
  DWORD Data;
  DWORD Lock;

  DWORD Format;   // Format information about the texture.
  DWORD Size;     // Size of a non power-of-2 texture, must be zero otherwise
};

#define D3DCOMMON_TYPE_MASK 0x0070000
#define D3DCOMMON_TYPE_TEXTURE 0x0040000

struct D3DPalette
{
  DWORD Common;
  DWORD Data;
  DWORD Lock;
};

typedef D3DPalette* LPDIRECT3DPALETTE8;

