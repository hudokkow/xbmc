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

#include "PlatformAndroid.h"
#include <stdlib.h>
#include "filesystem/SpecialProtocol.h"

CPlatform* CPlatform::CreateInstance()
{
  return new CPlatformAndroid();
}

CPlatformAndroid::CPlatformAndroid()
{
  
}

CPlatformAndroid::~CPlatformAndroid()
{
  
}

void CPlatformAndroid::Init()
{
    setenv("SSL_CERT_FILE", CSpecialProtocol::TranslatePath("special://xbmc/system/certs/cacert.pem").c_str(), 1);
}
