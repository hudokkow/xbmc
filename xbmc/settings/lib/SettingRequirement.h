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

class CSettingRequirementCondition : public CSettingConditionItem
{
public:
  explicit CSettingRequirementCondition(CSettingsManager *settingsManager = nullptr)
    : CSettingConditionItem(settingsManager)
  { }
  ~CSettingRequirementCondition() override = default;

  bool Check() const override;
};

class CSettingRequirementConditionCombination : public CSettingConditionCombination
{
public:
  explicit CSettingRequirementConditionCombination(CSettingsManager *settingsManager = nullptr)
    : CSettingConditionCombination(settingsManager)
  { }
  ~CSettingRequirementConditionCombination() override = default;

  bool Check() const override;

private:
  CBooleanLogicOperation* newOperation() override { return new CSettingRequirementConditionCombination(m_settingsManager); }
  CBooleanLogicValue* newValue() override { return new CSettingRequirementCondition(m_settingsManager); }
};

class CSettingRequirement : public CSettingCondition
{
public:
  explicit CSettingRequirement(CSettingsManager *settingsManager = nullptr);
  ~CSettingRequirement() override = default;
};
