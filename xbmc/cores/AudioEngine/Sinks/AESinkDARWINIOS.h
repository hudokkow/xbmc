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

#include "cores/AudioEngine/Interfaces/AESink.h"
#include "cores/AudioEngine/Utils/AEDeviceInfo.h"

#define DO_440HZ_TONE_TEST 0

#if DO_440HZ_TONE_TEST
typedef struct {
  float currentPhase;
  float phaseIncrement;
} SineWaveGenerator;
#endif

class AERingBuffer;
class CAAudioUnitSink;

class CAESinkDARWINIOS : public IAESink
{
public:
  virtual const char *GetName() { return "DARWINIOS"; }

  CAESinkDARWINIOS();
  virtual ~CAESinkDARWINIOS();

  static void Register();
  static void EnumerateDevicesEx(AEDeviceInfoList &list, bool force);
  static IAESink* Create(std::string &device, AEAudioFormat &desiredFormat);

  virtual bool Initialize(AEAudioFormat &format, std::string &device);
  virtual void Deinitialize();

  virtual void         GetDelay(AEDelayStatus& status);
  virtual double       GetCacheTotal   ();
  virtual unsigned int AddPackets      (uint8_t **data, unsigned int frames, unsigned int offset);
  virtual void         Drain           ();
  virtual bool         HasVolume       ();

private:
  static AEDeviceInfoList m_devices;
  CAEDeviceInfo      m_info;
  AEAudioFormat      m_format;

  CAAudioUnitSink   *m_audioSink;
#if DO_440HZ_TONE_TEST
  SineWaveGenerator  m_SineWaveGenerator;
#endif
};
