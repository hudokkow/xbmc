/*
 *      Copyright (C) 2016-present Team Kodi
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

namespace KODI
{
namespace JOYSTICK
{
  /*!
   * \ingroup joystick
   * \brief Interface for sending input events to joystick drivers
   */
  class IDriverReceiver
  {
  public:
    virtual ~IDriverReceiver() = default;

    /*!
     * \brief Set the value of a rumble motor
     *
     * \param motorIndex   The driver index of the motor to rumble
     * \param magnitude    The motor's new magnitude of vibration in the closed interval [0, 1]
     *
     * \return True if the event was handled otherwise false
     */
    virtual bool SetMotorState(unsigned int motorIndex, float magnitude) = 0;
  };
}
}
