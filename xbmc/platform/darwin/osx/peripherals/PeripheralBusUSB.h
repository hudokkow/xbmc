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

#include "peripherals/bus/PeripheralBus.h"
#include "peripherals/devices/Peripheral.h"

#ifdef TARGET_DARWIN_OSX
#include <IOKit/IOKitLib.h>
#include <IOKit/IOMessage.h>
#endif

namespace PERIPHERALS
{
  class CPeripherals;

  class CPeripheralBusUSB : public CPeripheralBus
  {
  public:
    explicit CPeripheralBusUSB(CPeripherals& manager);
    virtual ~CPeripheralBusUSB();

    /*!
     * @see PeripheralBus::PerformDeviceScan()
     */
    bool PerformDeviceScan(PeripheralScanResults &results);

  protected:
    PeripheralScanResults m_scan_results;
  #ifdef TARGET_DARWIN_OSX
    static PeripheralType GetType(int iDeviceClass);
    static void  DeviceDetachCallback(void *refCon, io_service_t service, natural_t messageType, void *messageArgument);
    static void  DeviceAttachCallback(CPeripheralBusUSB* refCon, io_iterator_t iterator);

    IONotificationPortRef m_notify_port;
    io_iterator_t         m_attach_iterator;
  #endif
  };

}
