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

#include "StreamUtils.h"

int StreamUtils::GetCodecPriority(const std::string &codec)
{
  /*
   * Technically flac, truehd, and dtshd_ma are equivalently good as they're all lossless. However,
   * ffmpeg can't decode dtshd_ma losslessy yet.
   */
  if (codec == "flac") // Lossless FLAC
    return 7;
  if (codec == "truehd") // Dolby TrueHD
    return 6;
  if (codec == "dtshd_ma") // DTS-HD Master Audio (previously known as DTS++)
    return 5;
  if (codec == "dtshd_hra") // DTS-HD High Resolution Audio
    return 4;
  if (codec == "eac3") // Dolby Digital Plus
    return 3;
  if (codec == "dca") // DTS
    return 2;
  if (codec == "ac3") // Dolby Digital
    return 1;
  return 0;
}
