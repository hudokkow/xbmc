#pragma once

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

/*
* CAddonProvider
* IUnknown implementation to retrieve sub-addons from already active addons
* See Inputstream.cpp/h for an explaric use case
*/

namespace kodi { namespace addon { class IAddonInstance; } }

namespace ADDON
{
  class CBinaryAddonBase;
  typedef std::shared_ptr<CBinaryAddonBase> BinaryAddonBasePtr;

  class IAddonProvider
  {
  public:
    virtual ~IAddonProvider() = default;
    enum INSTANCE_TYPE
    {
      INSTANCE_VIDEOCODEC
    };
    virtual void getAddonInstance(INSTANCE_TYPE instance_type, ADDON::BinaryAddonBasePtr& addonBase, kodi::addon::IAddonInstance*& parentInstance) = 0;
  };

  } //Namespace
