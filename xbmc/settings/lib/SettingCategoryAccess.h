#pragma once
/*
 *      Copyright (C) 2013-present Team Kodi
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

#include <set>
#include <string>

#include "SettingConditions.h"

class CSettingCategoryAccessCondition : public CSettingConditionItem
{
public:
  explicit CSettingCategoryAccessCondition(CSettingsManager *settingsManager = nullptr)
    : CSettingConditionItem(settingsManager)
  { }
  ~CSettingCategoryAccessCondition() override = default;

  bool Check() const override;
};

class CSettingCategoryAccessConditionCombination : public CSettingConditionCombination
{
public:
  explicit CSettingCategoryAccessConditionCombination(CSettingsManager *settingsManager = nullptr)
    : CSettingConditionCombination(settingsManager)
  { }
  ~CSettingCategoryAccessConditionCombination() override = default;

  bool Check() const override;

private:
  CBooleanLogicOperation* newOperation() override { return new CSettingCategoryAccessConditionCombination(m_settingsManager); }
  CBooleanLogicValue* newValue() override { return new CSettingCategoryAccessCondition(m_settingsManager); }
};

class CSettingCategoryAccess : public CSettingCondition
{
public:
  explicit CSettingCategoryAccess(CSettingsManager *settingsManager = nullptr);
  ~CSettingCategoryAccess() override = default;
};
