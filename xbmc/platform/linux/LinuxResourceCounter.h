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

#include <sys/time.h>
#include <sys/times.h>
#include <sys/resource.h>

#include <time.h>

class CLinuxResourceCounter
{
public:
  CLinuxResourceCounter();
  virtual ~CLinuxResourceCounter();

  double GetCPUUsage();
  void   Reset();

protected:
  struct rusage  m_usage;
  struct timeval m_tmLastCheck;
  double m_dLastUsage;
};

