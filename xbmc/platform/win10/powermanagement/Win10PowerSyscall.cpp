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

#include "Win10PowerSyscall.h"
#include <winrt/Windows.Devices.Power.h>

using namespace winrt::Windows::Devices::Power;

IPowerSyscall* CPowerSyscall::CreateInstance()
{
  return new CPowerSyscall();
}

void CPowerSyscall::Register()
{
  IPowerSyscall::RegisterPowerSyscall(CPowerSyscall::CreateInstance);
}

CPowerSyscall::CPowerSyscall() = default;

CPowerSyscall::~CPowerSyscall() = default;

bool CPowerSyscall::Powerdown()
{
  return false;
}
bool CPowerSyscall::Suspend()
{
  return false;
}
bool CPowerSyscall::Hibernate()
{
  return false;
}
bool CPowerSyscall::Reboot()
{
  return false;
}

bool CPowerSyscall::CanPowerdown()
{
  return false;
}
bool CPowerSyscall::CanSuspend()
{
  return false;
}
bool CPowerSyscall::CanHibernate()
{
  return false;
}
bool CPowerSyscall::CanReboot()
{
  return false;
}

int CPowerSyscall::BatteryLevel()
{
  int result = 0;
  auto aggBattery = Battery::AggregateBattery();
  auto report = aggBattery.GetReport();

  int remaining = 0;
  if (report.RemainingCapacityInMilliwattHours())
    remaining = report.RemainingCapacityInMilliwattHours().GetInt32();
  int full = 0;
  if (report.FullChargeCapacityInMilliwattHours())
    full = report.FullChargeCapacityInMilliwattHours().GetInt32();

  if (full != 0 && remaining != 0)
  {
    float percent = static_cast<float>(remaining) / static_cast<float>(full);
    result = static_cast<int> (percent * 100.0f);
  }
  return result;
}

bool CPowerSyscall::PumpPowerEvents(IPowerEventsCallback *callback)
{
  return true;
}
