#pragma once
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

#include <map>
#include <string>
#include <vector>

#include "events/IEvent.h"
#include "threads/CriticalSection.h"

#define NOTIFICATION_DISPLAY_TIME 5000
#define NOTIFICATION_MESSAGE_TIME 1000

typedef std::vector<EventPtr> Events;

class CEventLog
{
public:
  CEventLog() = default;
  CEventLog(const CEventLog&) = delete;
  CEventLog& operator=(CEventLog const&) = delete;
  ~CEventLog() = default;

  Events Get() const;
  Events Get(EventLevel level, bool includeHigherLevels = false) const;
  EventPtr Get(const std::string& eventIdentifier) const;

  void Add(const EventPtr& event);
  void Add(const EventPtr& event, bool withNotification, bool withSound = true);
  void AddWithNotification(const EventPtr& event,
                           unsigned int displayTime = NOTIFICATION_DISPLAY_TIME,
                           unsigned int messageTime = NOTIFICATION_MESSAGE_TIME,
                           bool withSound = true);
  void AddWithNotification(const EventPtr& event, bool withSound);
  void Remove(const EventPtr& event);
  void Remove(const std::string& eventIdentifier);
  void Clear();
  void Clear(EventLevel level, bool includeHigherLevels = false);

  bool Execute(const std::string& eventIdentifier);

  static std::string EventLevelToString(EventLevel level);
  static EventLevel EventLevelFromString(const std::string& level);

  void ShowFullEventLog(EventLevel level = EventLevel::Basic, bool includeHigherLevels = true);

private:
  void SendMessage(const EventPtr& event, int message);

  typedef std::vector<EventPtr> EventsList;
  typedef std::map<std::string, EventPtr> EventsMap;
  EventsList m_events;
  EventsMap m_eventsMap;
  CCriticalSection m_critical;
};
