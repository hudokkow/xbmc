/*
 *      Copyright (C) 2005-present Team Kodi
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

#include "LanguageHook.h"
#include "utils/GlobalsHandling.h"

namespace XBMCAddon
{
  // just need a place for the vtab
  LanguageHook::~LanguageHook() = default;

  static thread_local LanguageHook* addonLanguageHookTls;
  static bool threadLocalInitialized = false;
  static xbmcutil::InitFlag initer(threadLocalInitialized);

  void LanguageHook::SetLanguageHook(LanguageHook* languageHook)
  {
    XBMC_TRACE;
    languageHook->Acquire();
    addonLanguageHookTls = languageHook;
  }

  LanguageHook* LanguageHook::GetLanguageHook()
  {
    return threadLocalInitialized ? addonLanguageHookTls : NULL;
  }

  void LanguageHook::ClearLanguageHook()
  {
    LanguageHook* lh = addonLanguageHookTls;
    addonLanguageHookTls = NULL;
    if (lh)
      lh->Release();
  }
}
