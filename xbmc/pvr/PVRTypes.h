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

#include <memory>

namespace PVR
{
  class CPVRDatabase;
  typedef std::shared_ptr<CPVRDatabase> CPVRDatabasePtr;

  class CPVREpgDatabase;
  typedef std::shared_ptr<CPVREpgDatabase> CPVREpgDatabasePtr;

  class CPVRChannel;
  typedef std::shared_ptr<CPVRChannel> CPVRChannelPtr;

  class CPVRChannelGroup;
  typedef std::shared_ptr<CPVRChannelGroup> CPVRChannelGroupPtr;

  class CPVRChannelGroupsContainer;
  typedef std::shared_ptr<CPVRChannelGroupsContainer> CPVRChannelGroupsContainerPtr;

  class CPVRClients;
  typedef std::shared_ptr<CPVRClients> CPVRClientsPtr;

  class CPVRRadioRDSInfoTag;
  typedef std::shared_ptr<CPVRRadioRDSInfoTag> CPVRRadioRDSInfoTagPtr;

  class CPVRRecording;
  typedef std::shared_ptr<CPVRRecording> CPVRRecordingPtr;

  class CPVRRecordings;
  typedef std::shared_ptr<CPVRRecordings> CPVRRecordingsPtr;

  class CPVRTimerInfoTag;
  typedef std::shared_ptr<CPVRTimerInfoTag> CPVRTimerInfoTagPtr;

  class CPVRTimerType;
  typedef std::shared_ptr<CPVRTimerType> CPVRTimerTypePtr;

  class CPVRTimers;
  typedef std::shared_ptr<CPVRTimers> CPVRTimersPtr;

  class CPVRGUIActions;
  typedef std::shared_ptr<CPVRGUIActions> CPVRGUIActionsPtr;

  class CPVREpg;
  typedef std::shared_ptr<CPVREpg> CPVREpgPtr;

  class CPVREpgInfoTag;
  typedef std::shared_ptr<CPVREpgInfoTag> CPVREpgInfoTagPtr;
  typedef std::shared_ptr<const CPVREpgInfoTag> CConstPVREpgInfoTagPtr;

} // namespace PVR

