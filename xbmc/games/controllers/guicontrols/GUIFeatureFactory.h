/*
 *      Copyright (C) 2017-present Team Kodi
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
#pragma once

#include "GUIControlTypes.h"

class CGUIButtonControl;

namespace KODI
{
namespace GAME
{
  class CControllerFeature;
  class IConfigurationWizard;

  class CGUIFeatureFactory
  {
  public:
    /*!
     * \brief Create a button of the specified type
     * \param type The type of button control being created
     * \return A button control, or nullptr if type is invalid
     */
    static CGUIButtonControl* CreateButton(BUTTON_TYPE type,
                                           const CGUIButtonControl& buttonTemplate,
                                           IConfigurationWizard* wizard,
                                           const CControllerFeature& feature,
                                           unsigned int index);
  };
}
}
