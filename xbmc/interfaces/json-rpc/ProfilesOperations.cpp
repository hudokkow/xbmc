/*
 *      Copyright (C) 2013-present Team Kodi
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

#include "ProfilesOperations.h"
#include "messaging/ApplicationMessenger.h"
#include "guilib/LocalizeStrings.h"
#include "profiles/ProfilesManager.h"
#include "utils/Digest.h"
#include "utils/Variant.h"
#include "ServiceBroker.h"

using namespace JSONRPC;
using namespace KODI::MESSAGING;
using KODI::UTILITY::CDigest;

JSONRPC_STATUS CProfilesOperations::GetProfiles(const std::string &method, ITransportLayer *transport, IClient *client, const CVariant &parameterObject, CVariant &result)
{
  const CProfilesManager &profileManager = CServiceBroker::GetProfileManager();

  CFileItemList listItems;

  for (unsigned int i = 0; i < profileManager.GetNumberOfProfiles(); ++i)
  {
    const CProfile *profile = profileManager.GetProfile(i);
    CFileItemPtr item(new CFileItem(profile->getName()));
    item->SetArt("thumb", profile->getThumb());
    listItems.Add(item);
  }

  HandleFileItemList("profileid", false, "profiles", listItems, parameterObject, result);

  for (CVariant::const_iterator_array propertyiter = parameterObject["properties"].begin_array(); propertyiter != parameterObject["properties"].end_array(); ++propertyiter)
  {
    if (propertyiter->isString() &&
        propertyiter->asString() == "lockmode")
    {
      for (CVariant::iterator_array profileiter = result["profiles"].begin_array(); profileiter != result["profiles"].end_array(); ++profileiter)
      {
        std::string profilename = (*profileiter)["label"].asString();
        int index = profileManager.GetProfileIndex(profilename);
        const CProfile *profile = profileManager.GetProfile(index);
        LockType locktype = LOCK_MODE_UNKNOWN;
        if (index == 0)
          locktype = profileManager.GetMasterProfile().getLockMode();
        else
          locktype = profile->getLockMode();
        (*profileiter)["lockmode"] = locktype;
      }
      break;
    }
  }
  return OK;
}

JSONRPC_STATUS CProfilesOperations::GetCurrentProfile(const std::string &method, ITransportLayer *transport, IClient *client, const CVariant &parameterObject, CVariant &result)
{
  const CProfilesManager &profileManager = CServiceBroker::GetProfileManager();

  const CProfile& currentProfile = profileManager.GetCurrentProfile();
  CVariant profileVariant = CVariant(CVariant::VariantTypeObject);
  profileVariant["label"] = currentProfile.getName();
  for (CVariant::const_iterator_array propertyiter = parameterObject["properties"].begin_array(); propertyiter != parameterObject["properties"].end_array(); ++propertyiter)
  {
    if (propertyiter->isString())
    {
      if (propertyiter->asString() == "lockmode")
        profileVariant["lockmode"] = currentProfile.getLockMode();
      else if (propertyiter->asString() == "thumbnail")
        profileVariant["thumbnail"] = currentProfile.getThumb();
    }
  }

  result = profileVariant;

  return OK;
}

JSONRPC_STATUS CProfilesOperations::LoadProfile(const std::string &method, ITransportLayer *transport, IClient *client, const CVariant &parameterObject, CVariant &result)
{
  const CProfilesManager &profileManager = CServiceBroker::GetProfileManager();

  std::string profilename = parameterObject["profile"].asString();
  int index = profileManager.GetProfileIndex(profilename);
  
  if (index < 0)
    return InvalidParams;

  // get the profile
  const CProfile *profile = profileManager.GetProfile(index);
  if (profile == NULL)
    return InvalidParams;

  bool bPrompt = parameterObject["prompt"].asBoolean();
  bool bCanceled = false;
  bool bLoadProfile = false;

  // if the profile does not require a password or
  // the user is prompted and provides the correct password
  // we can load the requested profile
  if (profile->getLockMode() == LOCK_MODE_EVERYONE ||
     (bPrompt && g_passwordManager.IsProfileLockUnlocked(index, bCanceled, bPrompt)))
    bLoadProfile = true;
  else if (!bCanceled)  // Password needed and user provided it
  {
    const CVariant &passwordObject = parameterObject["password"];
    std::string strToVerify = profile->getLockCode();
    std::string password = passwordObject["value"].asString();
		
    // Create password hash from the provided password if md5 is not used
    std::string md5pword2;
    std::string encryption = passwordObject["encryption"].asString();
    if (encryption == "none")
      md5pword2 = CDigest::Calculate(CDigest::Type::MD5, password);
    else if (encryption == "md5")
      md5pword2 = password;

    // Verify provided password
    if (StringUtils::EqualsNoCase(strToVerify, md5pword2))
      bLoadProfile = true;
  }

  if (bLoadProfile)
  {
    CApplicationMessenger::GetInstance().PostMsg(TMSG_LOADPROFILE, index);
    return ACK;
  }
  return InvalidParams;
}
