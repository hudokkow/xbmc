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

#include "OSScreenSaverOSX.h"

#include <CoreFoundation/CoreFoundation.h>

COSScreenSaverOSX::COSScreenSaverOSX()
{
}

void COSScreenSaverOSX::Inhibit()
{
  // see Technical Q&A QA1340
  if (m_assertionID == 0)
  {
    CFStringRef reasonForActivity= CFSTR("XBMC requested disable system screen saver");
    IOPMAssertionCreateWithName(kIOPMAssertionTypeNoDisplaySleep,
      kIOPMAssertionLevelOn, reasonForActivity, &m_assertionID);
  }
}

void COSScreenSaverOSX::Uninhibit()
{
  if (m_assertionID != 0)
  {
    IOPMAssertionRelease(m_assertionID);
    m_assertionID = 0;
  }
}