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

#include <interface/mmal/util/mmal_default_components.h>
#include "ProcessInfoPi.h"
#include "platform/linux/RBP.h"
#include "cores/VideoPlayer/DVDCodecs/Video/MMALFFmpeg.h"

// Override for platform ports
#if defined(TARGET_RASPBERRY_PI)

using namespace MMAL;

CProcessInfo* CProcessInfoPi::Create()
{
  return new CProcessInfoPi();
}

CProcessInfoPi::CProcessInfoPi()
{
  /* Create dummy component with attached pool */
  std::shared_ptr<IVideoBufferPool> pool = std::make_shared<CMMALPool>(MMAL_COMPONENT_DEFAULT_VIDEO_DECODER, false, MMAL_NUM_OUTPUT_BUFFERS, 0, MMAL_ENCODING_UNKNOWN, MMALStateFFDec);
  m_videoBufferManager.RegisterPool(pool);
}

void CProcessInfoPi::Register()
{
  CProcessInfo::RegisterProcessControl("rbpi", CProcessInfoPi::Create);
}

EINTERLACEMETHOD CProcessInfoPi::GetFallbackDeintMethod()
{
  return EINTERLACEMETHOD::VS_INTERLACEMETHOD_DEINTERLACE_HALF;
}

bool CProcessInfoPi::AllowDTSHDDecode()
{
  if (g_RBP.RaspberryPiVersion() == 1)
    return false;
  return true;
}

#endif

