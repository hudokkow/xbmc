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

#include "SavestateTranslator.h"
#include "SavestateDefines.h"

using namespace KODI;
using namespace GAME;

SAVETYPE CSavestateTranslator::TranslateType(const std::string& type)
{
  if      (type == SAVESTATE_TYPE_AUTO)   return SAVETYPE::AUTO;
  else if (type == SAVESTATE_TYPE_SLOT)   return SAVETYPE::SLOT;
  else if (type == SAVESTATE_TYPE_MANUAL) return SAVETYPE::MANUAL;

  return SAVETYPE::UNKNOWN;
}

std::string CSavestateTranslator::TranslateType(const SAVETYPE& type)
{
  switch (type)
  {
    case SAVETYPE::AUTO:   return SAVESTATE_TYPE_AUTO;
    case SAVETYPE::SLOT:   return SAVESTATE_TYPE_SLOT;
    case SAVETYPE::MANUAL: return SAVESTATE_TYPE_MANUAL;
    default:
      break;
  }
  return SAVESTATE_TYPE_UNKNOWN;
}
