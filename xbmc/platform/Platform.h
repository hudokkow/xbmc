#pragma once

/*
 *      Copyright (C) 2016-present Team Kodi
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


/**\brief Class for the Platform object
 *
 * Contains method which retrieve platform specific information
 * and methods for doing platform specific environment preparation/initialisation
 */
class CPlatform
{
public:
  /**\brief Creates the Platform object
   *
   *@return the platform object 
  */
  static CPlatform *CreateInstance();
  
  /**\brief C'tor */
  CPlatform();
  
  /**\brief D'tor */
  virtual ~CPlatform();
  
  /**\brief Called at an early stage of application startup
   *
   * This method can be used to do platform specific environment preparation
   * or initialisation (like setting environment variables for example)
   */
  virtual void Init();
  
};