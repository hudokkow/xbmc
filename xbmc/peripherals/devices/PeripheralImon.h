#pragma once
/*
 *      Copyright (C) 2012-present Team Kodi
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

#include "PeripheralHID.h"

#include <atomic>

class CSetting;

namespace PERIPHERALS
{
  class CPeripheralImon : public CPeripheralHID
  {
  public:
    CPeripheralImon(CPeripherals& manager, const PeripheralScanResult& scanResult, CPeripheralBus* bus);
    ~CPeripheralImon(void) override = default;
    bool InitialiseFeature(const PeripheralFeature feature) override;
    void OnSettingChanged(const std::string &strChangedSetting) override;
    void OnDeviceRemoved() override;
    void AddSetting(const std::string &strKey, std::shared_ptr<const CSetting> setting, int order) override;
    inline bool IsImonConflictsWithDInput() 
    { return m_bImonConflictsWithDInput;}
    static inline long GetCountOfImonsConflictWithDInput()
    { return m_lCountOfImonsConflictWithDInput; }
    static void ActionOnImonConflict(bool deviceInserted = true);

  private:
    bool m_bImonConflictsWithDInput;
    static std::atomic<long> m_lCountOfImonsConflictWithDInput;
  };
}
