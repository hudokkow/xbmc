#pragma once
/*
 *      Copyright (C) 2012-present Team Kodi
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

#include <android/input.h>

class CAndroidMouse
{

public:
  CAndroidMouse();
  virtual ~CAndroidMouse();
  bool onMouseEvent(AInputEvent* event);

protected:

private:
  void MouseMove(float x, float y);
  void MouseButton(float x, float y, int32_t type, int32_t buttons);
  void MouseWheel(float x, float y, float value);

private:
  int32_t m_lastButtonState;
};
