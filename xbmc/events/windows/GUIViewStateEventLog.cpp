/*
 *      Copyright (C) 2015-present Team Kodi
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

#include "GUIViewStateEventLog.h"
#include "FileItem.h"
#include "filesystem/File.h"
#include "windowing/GraphicContext.h"
#include "guilib/WindowIDs.h"
#include "utils/StringUtils.h"
#include "view/ViewState.h"

CGUIViewStateEventLog::CGUIViewStateEventLog(const CFileItemList& items) : CGUIViewState(items)
{
  AddSortMethod(SortByDate, 552, LABEL_MASKS("%L", "%d", "%L", "%d"));  // Label, Date | Label, Date

  SetSortMethod(SortByDate);
  SetViewAsControl(DEFAULT_VIEW_AUTO);

  SetSortOrder(SortOrderDescending);
  LoadViewState(items.GetPath(), WINDOW_EVENT_LOG);
}

void CGUIViewStateEventLog::SaveViewState()
{
  SaveViewToDb(m_items.GetPath(), WINDOW_EVENT_LOG);
}

std::string CGUIViewStateEventLog::GetExtensions()
{
  return "";
}
