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

#include "ContextMenus.h"
#include "AddonManager.h"
#include "Repository.h"
#include "RepositoryUpdater.h"
#include "ServiceBroker.h"
#include "GUIDialogAddonInfo.h"
#include "settings/GUIDialogAddonSettings.h"


namespace CONTEXTMENU
{

using namespace ADDON;

bool CAddonSettings::IsVisible(const CFileItem& item) const
{
  AddonPtr addon;
  return item.HasAddonInfo()
         && CServiceBroker::GetAddonMgr().GetAddon(item.GetAddonInfo()->ID(), addon, ADDON_UNKNOWN, false)
         && addon->HasSettings();
}

bool CAddonSettings::Execute(const CFileItemPtr& item) const
{
  AddonPtr addon;
  return CServiceBroker::GetAddonMgr().GetAddon(item->GetAddonInfo()->ID(), addon, ADDON_UNKNOWN, false)
         && CGUIDialogAddonSettings::ShowForAddon(addon);
}

bool CCheckForUpdates::IsVisible(const CFileItem& item) const
{
  return item.HasAddonInfo() && item.GetAddonInfo()->Type() == ADDON::ADDON_REPOSITORY;
}

bool CCheckForUpdates::Execute(const CFileItemPtr& item) const
{
  AddonPtr addon;
  if (item->HasAddonInfo() && CServiceBroker::GetAddonMgr().GetAddon(item->GetAddonInfo()->ID(), addon, ADDON_REPOSITORY))
  {
    CServiceBroker::GetRepositoryUpdater().CheckForUpdates(std::static_pointer_cast<CRepository>(addon), true);
    return true;
  }
  return false;
}


bool CEnableAddon::IsVisible(const CFileItem& item) const
{
  return item.HasAddonInfo() &&
      CServiceBroker::GetAddonMgr().IsAddonDisabled(item.GetAddonInfo()->ID()) &&
      CServiceBroker::GetAddonMgr().CanAddonBeEnabled(item.GetAddonInfo()->ID());
}

bool CEnableAddon::Execute(const CFileItemPtr& item) const
{
  return CServiceBroker::GetAddonMgr().EnableAddon(item->GetAddonInfo()->ID());
}

bool CDisableAddon::IsVisible(const CFileItem& item) const
{
  return item.HasAddonInfo() &&
      !CServiceBroker::GetAddonMgr().IsAddonDisabled(item.GetAddonInfo()->ID()) &&
      CServiceBroker::GetAddonMgr().CanAddonBeDisabled(item.GetAddonInfo()->ID());
}

bool CDisableAddon::Execute(const CFileItemPtr& item) const
{
  return CServiceBroker::GetAddonMgr().DisableAddon(item->GetAddonInfo()->ID());
}
}
