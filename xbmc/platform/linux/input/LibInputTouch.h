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

#include "input/touch/generic/GenericTouchInputHandler.h"
#include "utils/Geometry.h"

#include <libinput.h>
#include <vector>

struct libinput_event_touch;
struct libinput_device;

class CLibInputTouch
{
public:
  CLibInputTouch();
  void ProcessTouchDown(libinput_event_touch *e);
  void ProcessTouchMotion(libinput_event_touch *e);
  void ProcessTouchUp(libinput_event_touch *e);
  void ProcessTouchCancel(libinput_event_touch *e);
  void ProcessTouchFrame(libinput_event_touch *e);

private:
  std::vector<std::pair<TouchInput, CPoint>> m_points;
};
