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

#include <memory>
#include <string>
#include <utility>
#include <vector>

#define SETTING_XML_ROOT "settings"
#define SETTING_XML_ROOT_VERSION "version"

#define SETTING_XML_ELM_SECTION "section"
#define SETTING_XML_ELM_CATEGORY "category"
#define SETTING_XML_ELM_GROUP "group"
#define SETTING_XML_ELM_SETTING "setting"
#define SETTING_XML_ELM_VISIBLE "visible"
#define SETTING_XML_ELM_REQUIREMENT "requirement"
#define SETTING_XML_ELM_CONDITION "condition"
#define SETTING_XML_ELM_LEVEL "level"
#define SETTING_XML_ELM_DEFAULT "default"
#define SETTING_XML_ELM_VALUE "value"
#define SETTING_XML_ELM_CONTROL "control"
#define SETTING_XML_ELM_CONSTRAINTS "constraints"
#define SETTING_XML_ELM_OPTIONS "options"
#define SETTING_XML_ELM_OPTION "option"
#define SETTING_XML_ELM_MINIMUM "minimum"
#define SETTING_XML_ELM_STEP "step"
#define SETTING_XML_ELM_MAXIMUM "maximum"
#define SETTING_XML_ELM_ALLOWEMPTY "allowempty"
#define SETTING_XML_ELM_DEPENDENCIES "dependencies"
#define SETTING_XML_ELM_DEPENDENCY "dependency"
#define SETTING_XML_ELM_UPDATES "updates"
#define SETTING_XML_ELM_UPDATE "update"
#define SETTING_XML_ELM_ACCESS "access"
#define SETTING_XML_ELM_DELIMITER "delimiter"
#define SETTING_XML_ELM_MINIMUM_ITEMS "minimumitems"
#define SETTING_XML_ELM_MAXIMUM_ITEMS "maximumitems"
#define SETTING_XML_ELM_DATA "data"

#define SETTING_XML_ATTR_ID "id"
#define SETTING_XML_ATTR_LABEL "label"
#define SETTING_XML_ATTR_HELP "help"
#define SETTING_XML_ATTR_TYPE "type"
#define SETTING_XML_ATTR_PARENT "parent"
#define SETTING_XML_ATTR_FORMAT "format"
#define SETTING_XML_ATTR_DELAYED "delayed"
#define SETTING_XML_ATTR_ON "on"
#define SETTING_XML_ATTR_OPERATOR "operator"
#define SETTING_XML_ATTR_NAME "name"
#define SETTING_XML_ATTR_SETTING "setting"
#define SETTING_XML_ATTR_BEFORE "before"
#define SETTING_XML_ATTR_AFTER "after"

using TranslatableIntegerSettingOption = std::pair<int, int>;
using TranslatableIntegerSettingOptions = std::vector<TranslatableIntegerSettingOption>;
using IntegerSettingOption = std::pair<std::string, int>;
using IntegerSettingOptions = std::vector<IntegerSettingOption>;
using TranslatableStringSettingOption = std::pair<int, std::string>;
using TranslatableStringSettingOptions = std::vector<TranslatableStringSettingOption>;
using StringSettingOption = std::pair<std::string, std::string>;
using StringSettingOptions = std::vector<StringSettingOption>;

class CSetting;
using IntegerSettingOptionsFiller = void (*)(std::shared_ptr<const CSetting> setting, IntegerSettingOptions &list, int &current, void *data);
using StringSettingOptionsFiller = void (*)(std::shared_ptr<const CSetting> setting, StringSettingOptions &list, std::string &current, void *data);
