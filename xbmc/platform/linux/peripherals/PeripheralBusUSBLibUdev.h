#pragma once
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

#include "peripherals/bus/PeripheralBus.h"
#include "peripherals/devices/Peripheral.h"

struct udev;
struct udev_monitor;

namespace PERIPHERALS
{
  class CPeripherals;

  class CPeripheralBusUSB : public CPeripheralBus
  {
  public:
    explicit CPeripheralBusUSB(CPeripherals& manager);
    ~CPeripheralBusUSB(void) override;

    void Clear(void) override;

    /*!
     * @see PeripheralBus::PerformDeviceScan()
     */
    bool PerformDeviceScan(PeripheralScanResults &results) override;

  protected:
    static const PeripheralType GetType(int iDeviceClass);

    void Process(void) override;
    bool WaitForUpdate(void);

    struct udev *        m_udev;
    struct udev_monitor *m_udevMon;
  };
}
