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

#if defined (TARGET_DARWIN)
#include "powermanagement/IPowerSyscall.h"
#if defined(TARGET_DARWIN_IOS)
#include <pthread.h>
typedef mach_port_t io_object_t;
typedef io_object_t io_service_t;
#else
#include <IOKit/pwr_mgt/IOPMLib.h>
#include <IOKit/IOMessage.h>
#endif

class CCocoaPowerSyscall : public CPowerSyscallWithoutEvents
{
public:
  CCocoaPowerSyscall();
  ~CCocoaPowerSyscall();

  static IPowerSyscall* CreateInstance();
  static void Register();

  virtual bool Powerdown(void);
  virtual bool Suspend(void);
  virtual bool Hibernate(void);
  virtual bool Reboot(void);

  virtual bool CanPowerdown(void);
  virtual bool CanSuspend(void);
  virtual bool CanHibernate(void);
  virtual bool CanReboot(void);
          bool HasBattery(void);
  virtual int  BatteryLevel(void);

  virtual bool PumpPowerEvents(IPowerEventsCallback *callback);
private:
          void CreateOSPowerCallBacks(void);
          void DeleteOSPowerCallBacks(void);
  static  void OSPowerCallBack(void *refcon, io_service_t service, natural_t msg_type, void *msg_arg);
  static  void OSPowerSourceCallBack(void *refcon);

  // OS Power
  bool m_OnResume;
  bool m_OnSuspend;
  // OS Power Source
  bool m_OnBattery;
  int  m_HasBattery;
  int  m_BatteryPercent;
  bool m_SentBatteryMessage;

#if defined(TARGET_DARWIN_OSX)
  io_connect_t m_root_port;             // a reference to the Root Power Domain IOService
  io_object_t  m_notifier_object;       // notifier object, used to deregister later
  IONotificationPortRef m_notify_port;  // notification port allocated by IORegisterForSystemPower
  CFRunLoopSourceRef m_power_source;
#endif
};
#endif

