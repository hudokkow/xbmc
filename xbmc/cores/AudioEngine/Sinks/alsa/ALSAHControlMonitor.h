#pragma once
/*
 *      Copyright (C) 2014-present Team Kodi
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

#include <string>
#include <map>
#include <vector>

#include <alsa/asoundlib.h>

class CALSAHControlMonitor
{
public:
  CALSAHControlMonitor();
  ~CALSAHControlMonitor();

  bool Add(const std::string& ctlHandleName,
           snd_ctl_elem_iface_t interface,
           unsigned int device,
           const std::string& name);

  void Clear();

  void Start();
  void Stop();

private:
  static int HCTLCallback(snd_hctl_elem_t *elem, unsigned int mask);
  static void FDEventCallback(int id, int fd, short revents, void *data);

  snd_hctl_t* GetHandle(const std::string& ctlHandleName);
  void PutHandle(const std::string& ctlHandleName);

  struct CTLHandle
  {
    snd_hctl_t *handle;
    int useCount;

    explicit CTLHandle(snd_hctl_t *handle_) : handle(handle_), useCount(0) {}
    CTLHandle() : handle(NULL), useCount(0) {}
  };

  std::map<std::string, CTLHandle> m_ctlHandles;

  std::vector<int> m_fdMonitorIds;
};
