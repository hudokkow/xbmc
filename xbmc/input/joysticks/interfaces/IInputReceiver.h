/*
 *      Copyright (C) 2014-present Team Kodi
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

#include "input/joysticks/JoystickTypes.h"

namespace KODI
{
namespace JOYSTICK
{
  /*!
   * \ingroup joystick
   * \brief Interface for sending input events to game controllers
   */
  class IInputReceiver
  {
  public:
    virtual ~IInputReceiver() = default;

    /*!
     * \brief Set the value of a rumble motor
     *
     * \param feature      The name of the motor to rumble
     * \param magnitude    The motor's new magnitude of vibration in the closed interval [0, 1]
     *
     * \return True if the event was handled otherwise false
     */
    virtual bool SetRumbleState(const FeatureName& feature, float magnitude) = 0;
  };
}
}
