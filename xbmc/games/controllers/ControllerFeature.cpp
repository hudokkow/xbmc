/*
 *      Copyright (C) 2015-present Team Kodi
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

#include "ControllerFeature.h"
#include "Controller.h"
#include "ControllerDefinitions.h"
#include "ControllerTranslator.h"
#include "guilib/LocalizeStrings.h"
#include "utils/log.h"
#include "utils/XMLUtils.h"

#include <sstream>

using namespace KODI;
using namespace GAME;
using namespace JOYSTICK;

CControllerFeature::CControllerFeature(int labelId)
{
  Reset();
  m_labelId = labelId;
}

void CControllerFeature::Reset(void)
{
  *this = CControllerFeature();
}

CControllerFeature& CControllerFeature::operator=(const CControllerFeature& rhs)
{
  if (this != &rhs)
  {
    m_controller = rhs.m_controller;
    m_type = rhs.m_type;
    m_category = rhs.m_category;
    m_categoryLabelId = rhs.m_categoryLabelId;
    m_strName = rhs.m_strName;
    m_labelId = rhs.m_labelId;
    m_inputType = rhs.m_inputType;
    m_keycode = rhs.m_keycode;
  }
  return *this;
}

std::string CControllerFeature::CategoryLabel() const
{
  std::string categoryLabel;

  if (m_categoryLabelId >= 0 && m_controller != nullptr)
    categoryLabel = g_localizeStrings.GetAddonString(m_controller->ID(), m_categoryLabelId);

  if (categoryLabel.empty())
    categoryLabel = g_localizeStrings.Get(m_categoryLabelId);

  return categoryLabel;
}

std::string CControllerFeature::Label() const
{
  std::string label;

  if (m_labelId >= 0 && m_controller != nullptr)
    label = g_localizeStrings.GetAddonString(m_controller->ID(), m_labelId);

  if (label.empty())
    label = g_localizeStrings.Get(m_labelId);

  return label;
}

bool CControllerFeature::Deserialize(const TiXmlElement* pElement,
                                     const CController* controller,
                                     FEATURE_CATEGORY category,
                                     int categoryLabelId)
{
  Reset();

  if (!pElement)
    return false;

  std::string strType(pElement->Value());

  // Type
  m_type = CControllerTranslator::TranslateFeatureType(strType);
  if (m_type == FEATURE_TYPE::UNKNOWN)
  {
    CLog::Log(LOGDEBUG, "Invalid feature: <%s> ", pElement->Value());
    return false;
  }

  // Cagegory was obtained from parent XML node
  m_category = category;
  m_categoryLabelId = categoryLabelId;

  // Name
  m_strName = XMLUtils::GetAttribute(pElement, LAYOUT_XML_ATTR_FEATURE_NAME);
  if (m_strName.empty())
  {
    CLog::Log(LOGERROR, "<%s> tag has no \"%s\" attribute", strType.c_str(), LAYOUT_XML_ATTR_FEATURE_NAME);
    return false;
  }

  // Label ID
  std::string strLabel = XMLUtils::GetAttribute(pElement, LAYOUT_XML_ATTR_FEATURE_LABEL);
  if (strLabel.empty())
    CLog::Log(LOGDEBUG, "<%s> tag has no \"%s\" attribute", strType.c_str(), LAYOUT_XML_ATTR_FEATURE_LABEL);
  else
    std::istringstream(strLabel) >> m_labelId;

  // Input type
  if (m_type == FEATURE_TYPE::SCALAR)
  {
    std::string strInputType = XMLUtils::GetAttribute(pElement, LAYOUT_XML_ATTR_INPUT_TYPE);
    if (strInputType.empty())
    {
      CLog::Log(LOGERROR, "<%s> tag has no \"%s\" attribute", strType.c_str(), LAYOUT_XML_ATTR_INPUT_TYPE);
      return false;
    }
    else
    {
      m_inputType = CControllerTranslator::TranslateInputType(strInputType);
      if (m_inputType == INPUT_TYPE::UNKNOWN)
      {
        CLog::Log(LOGERROR, "<%s> tag - attribute \"%s\" is invalid: \"%s\"",
                  strType.c_str(), LAYOUT_XML_ATTR_INPUT_TYPE, strInputType.c_str());
        return false;
      }
    }
  }

  // Keycode
  if (m_type == FEATURE_TYPE::KEY)
  {
    std::string strSymbol = XMLUtils::GetAttribute(pElement, LAYOUT_XML_ATTR_KEY_SYMBOL);
    if (strSymbol.empty())
    {
      CLog::Log(LOGERROR, "<%s> tag has no \"%s\" attribute", strType.c_str(), LAYOUT_XML_ATTR_KEY_SYMBOL);
      return false;
    }
    else
    {
      m_keycode = CControllerTranslator::TranslateKeysym(strSymbol);
      if (m_keycode == XBMCK_UNKNOWN)
      {
        CLog::Log(LOGERROR, "<%s> tag - attribute \"%s\" is invalid: \"%s\"",
                  strType.c_str(), LAYOUT_XML_ATTR_KEY_SYMBOL, strSymbol.c_str());
        return false;
      }
    }
  }

  // Save controller for string translation
  m_controller = controller;

  return true;
}
