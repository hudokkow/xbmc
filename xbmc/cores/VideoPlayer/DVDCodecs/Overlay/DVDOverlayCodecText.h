#pragma once

/*
 *      Copyright (C) 2005-present Team Kodi
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

#include "DVDOverlayCodec.h"

class CDVDOverlayText;

class CDVDOverlayCodecText : public CDVDOverlayCodec
{
public:
  CDVDOverlayCodecText();
  ~CDVDOverlayCodecText() override;
  bool Open(CDVDStreamInfo &hints, CDVDCodecOptions &options) override;
  void Dispose() override;
  int Decode(DemuxPacket *pPacket) override;
  void Reset() override;
  void Flush() override;
  CDVDOverlay* GetOverlay() override;

private:
  bool             m_bIsSSA;
  CDVDOverlayText* m_pOverlay;
};
