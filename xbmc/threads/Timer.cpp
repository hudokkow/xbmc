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

#include <algorithm>

#include "Timer.h"
#include "SystemClock.h"

CTimer::CTimer(std::function<void()> const& callback)
  : CThread("Timer"),
    m_callback(callback),
    m_timeout(0),
    m_interval(false),
    m_endTime(0)
{ }

CTimer::CTimer(ITimerCallback *callback)
  : CTimer(std::bind(&ITimerCallback::OnTimeout, callback))
{ }

CTimer::~CTimer()
{
  Stop(true);
}

bool CTimer::Start(uint32_t timeout, bool interval /* = false */)
{
  if (m_callback == NULL || timeout == 0 || IsRunning())
    return false;

  m_timeout = timeout;
  m_interval = interval;

  Create();
  return true;
}

bool CTimer::Stop(bool wait /* = false */)
{
  if (!IsRunning())
    return false;

  m_bStop = true;
  m_eventTimeout.Set();
  StopThread(wait);

  return true;
}

void CTimer::RestartAsync(uint32_t timeout)
{
  m_timeout = timeout;
  m_endTime = XbmcThreads::SystemClockMillis() + timeout;
  m_eventTimeout.Set();
}

bool CTimer::Restart()
{
  if (!IsRunning())
    return false;

  Stop(true);
  return Start(m_timeout, m_interval);
}

float CTimer::GetElapsedSeconds() const
{
  return GetElapsedMilliseconds() / 1000.0f;
}

float CTimer::GetElapsedMilliseconds() const
{
  if (!IsRunning())
    return 0.0f;

  return (float)(XbmcThreads::SystemClockMillis() - (m_endTime - m_timeout));
}

void CTimer::Process()
{
  while (!m_bStop)
  {
    uint32_t currentTime = XbmcThreads::SystemClockMillis();
    m_endTime = currentTime + m_timeout;

    // wait the necessary time
    if (!m_eventTimeout.WaitMSec(m_endTime - currentTime))
    {
      currentTime = XbmcThreads::SystemClockMillis();
      if (m_endTime <= currentTime)
      {
        // execute OnTimeout() callback
        m_callback();

        // continue if this is an interval timer, or if it was restarted during callback
        if (!m_interval && m_endTime <= currentTime)
          break;
      }
    }
  }
}