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

#include "ContextMenu.h"
#include "addons/kodi-addon-dev-kit/include/kodi/gui/dialogs/ContextMenu.h"

#include "addons/binary-addons/AddonDll.h"
#include "dialogs/GUIDialogContextMenu.h"
#include "guilib/GUIComponent.h"
#include "guilib/GUIWindowManager.h"
#include "utils/log.h"
#include "utils/Variant.h"
#include "ServiceBroker.h"

extern "C"
{
namespace ADDON
{

void Interface_GUIDialogContextMenu::Init(AddonGlobalInterface* addonInterface)
{
  addonInterface->toKodi->kodi_gui->dialogContextMenu = static_cast<AddonToKodiFuncTable_kodi_gui_dialogContextMenu*>(malloc(sizeof(AddonToKodiFuncTable_kodi_gui_dialogContextMenu)));

  addonInterface->toKodi->kodi_gui->dialogContextMenu->open = open;
}

void Interface_GUIDialogContextMenu::DeInit(AddonGlobalInterface* addonInterface)
{
  free(addonInterface->toKodi->kodi_gui->dialogContextMenu);
}

int Interface_GUIDialogContextMenu::open(void* kodiBase, const char *heading, const char *entries[], unsigned int size)
{
  CAddonDll* addon = static_cast<CAddonDll*>(kodiBase);
  if (!addon)
  {
    CLog::Log(LOGERROR, "Interface_GUIDialogContextMenu::%s - invalid data", __FUNCTION__);
    return -1;
  }

  CGUIDialogContextMenu* dialog = CServiceBroker::GetGUI()->GetWindowManager().GetWindow<CGUIDialogContextMenu>(WINDOW_DIALOG_CONTEXT_MENU);
  if (!heading || !entries || !dialog)
  {
    CLog::Log(LOGERROR,
              "Interface_GUIDialogContextMenu::%s - invalid handler data (heading='%p', "
              "entries='%p', dialog='%p') on addon '%s'",
              __FUNCTION__, heading, static_cast<const void*>(entries), kodiBase,
              addon->ID().c_str());
    return -1;
  }

  CContextButtons choices;
  for (unsigned int i = 0; i < size; ++i)
    choices.Add(i, entries[i]);

  return dialog->Show(choices);
}

} /* namespace ADDON */
} /* extern "C" */
