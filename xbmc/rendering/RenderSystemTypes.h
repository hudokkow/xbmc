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

enum RENDER_STEREO_VIEW
{
  RENDER_STEREO_VIEW_OFF,
  RENDER_STEREO_VIEW_LEFT,
  RENDER_STEREO_VIEW_RIGHT,
};

enum RENDER_STEREO_MODE
{
  RENDER_STEREO_MODE_OFF,
  RENDER_STEREO_MODE_SPLIT_HORIZONTAL,
  RENDER_STEREO_MODE_SPLIT_VERTICAL,
  RENDER_STEREO_MODE_ANAGLYPH_RED_CYAN,
  RENDER_STEREO_MODE_ANAGLYPH_GREEN_MAGENTA,
  RENDER_STEREO_MODE_ANAGLYPH_YELLOW_BLUE,
  RENDER_STEREO_MODE_INTERLACED,
  RENDER_STEREO_MODE_CHECKERBOARD,
  RENDER_STEREO_MODE_HARDWAREBASED,
  RENDER_STEREO_MODE_MONO,
  RENDER_STEREO_MODE_COUNT,

  // Pseudo modes
  RENDER_STEREO_MODE_AUTO = 100,
  RENDER_STEREO_MODE_UNDEFINED = 999,
};
