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

#pragma once

#include <vector>
#include <map>
#include "IListProvider.h"
#include "threads/CriticalSection.h"

typedef std::shared_ptr<IListProvider> IListProviderPtr;

/*!
 \ingroup listproviders
 \brief A listprovider that handles multiple individual providers.
 */
class CMultiProvider : public IListProvider
{
public:
  CMultiProvider(const TiXmlNode *first, int parentID);
  
  bool Update(bool forceRefresh) override;
  void Fetch(std::vector<CGUIListItemPtr> &items) override;
  bool IsUpdating() const override;
  void Reset() override;
  bool OnClick(const CGUIListItemPtr &item) override;
  bool OnInfo(const CGUIListItemPtr &item) override;
  bool OnContextMenu(const CGUIListItemPtr &item) override;
  
protected:
  typedef size_t item_key_type;
  static item_key_type GetItemKey(CGUIListItemPtr const &item);
  std::vector<IListProviderPtr> m_providers;
  std::map<item_key_type, IListProviderPtr> m_itemMap;
  CCriticalSection m_section; // protects m_itemMap
};
