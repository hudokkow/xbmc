#pragma once
/*
 *      Copyright (C) 2012-present Team Kodi
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

#include <stdint.h>

struct ANativeWindow;
typedef struct ANativeWindow ANativeWindow;

typedef enum
{
  ActivityOK    = 0,
  ActivityExit  = -1,
  ActivityError = -2,
  ActivityUnknown = 1
} ActivityResult;

class IActivityHandler
{
public:

  virtual void onStart() {}
  virtual void onResume() {}
  virtual void onPause() {}
  virtual void onStop() {}
  virtual void onDestroy() {}

  virtual void onSaveState(void **data, size_t *size) {}
  virtual void onConfigurationChanged() {}
  virtual void onLowMemory() {}

  virtual void onCreateWindow(ANativeWindow* window) {}
  virtual void onResizeWindow() {}
  virtual void onDestroyWindow() {}
  virtual void onGainFocus() {}
  virtual void onLostFocus() {}
};

