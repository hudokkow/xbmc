/*
 *      Copyright (C) 2017-present Team Kodi
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
#pragma once

#include "GUIFeatureButton.h"
#include "games/controllers/ControllerFeature.h"

namespace KODI
{
namespace GAME
{
  class CGUISelectKeyButton : public CGUIFeatureButton
  {
  public:
    CGUISelectKeyButton(const CGUIButtonControl& buttonTemplate,
                        IConfigurationWizard* wizard,
                        unsigned int index);

    virtual ~CGUISelectKeyButton() = default;

    // implementation of IFeatureButton
    const CControllerFeature& Feature(void) const override;
    bool AllowWizard() const override { return false; }
    virtual bool PromptForInput(CEvent& waitEvent) override;
    virtual bool IsFinished(void) const override;
    bool NeedsKey() const override { return m_state == STATE::NEED_KEY; }
    void SetKey(const CControllerFeature &key) override;
    virtual void Reset(void) override;

  private:
    static CControllerFeature GetFeature();

    enum class STATE
    {
      NEED_KEY,
      NEED_INPUT,
      FINISHED,
    };

    STATE m_state = STATE::NEED_KEY;

    CControllerFeature m_selectedKey;
  };
}
}
