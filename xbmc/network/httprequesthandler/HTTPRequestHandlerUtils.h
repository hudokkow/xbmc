#pragma once
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

#include <stdint.h>
#include <string>

#include "network/httprequesthandler/IHTTPRequestHandler.h"

class HTTPRequestHandlerUtils
{
public:
  static std::string GetRequestHeaderValue(struct MHD_Connection *connection, enum MHD_ValueKind kind, const std::string &key);
  static int GetRequestHeaderValues(struct MHD_Connection *connection, enum MHD_ValueKind kind, std::map<std::string, std::string> &headerValues);
  static int GetRequestHeaderValues(struct MHD_Connection *connection, enum MHD_ValueKind kind, std::multimap<std::string, std::string> &headerValues);

  static bool GetRequestedRanges(struct MHD_Connection *connection, uint64_t totalLength, CHttpRanges &ranges);

private:
  HTTPRequestHandlerUtils() = delete;

  static int FillArgumentMap(void *cls, enum MHD_ValueKind kind, const char *key, const char *value);
  static int FillArgumentMultiMap(void *cls, enum MHD_ValueKind kind, const char *key, const char *value);
};
