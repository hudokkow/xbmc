#pragma once
/*
 *      Copyright (C) 2010-present Team Kodi
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

#include "cores/AudioEngine/Interfaces/AEResample.h"

class IAEResample;

namespace ActiveAE
{

/**
 * Bit options to pass to CAEResampleFactory::Create
 */
enum AEResampleFactoryOptions
{
  /* This is a quick resample job (e.g. resample a single noise packet) and may not be worth using GPU acceleration */
  AERESAMPLEFACTORY_QUICK_RESAMPLE = 0x01
};

class CAEResampleFactory
{
public:
  static IAEResample *Create(uint32_t flags = 0U);
};

}
