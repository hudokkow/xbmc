/*
 *      Copyright (C) 2011-present Team Kodi
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

#include <Winsock2.h>
#include <WS2tcpip.h>
#include <ws2bth.h>

#ifndef SHUT_RDWR
#define SHUT_RDWR SD_BOTH
#endif

#ifndef SHUT_RD
#define SHUT_RD SD_RECEIVE
#endif

#ifndef SHUT_WR
#define SHUT_WR SD_SEND
#endif


#ifndef AF_BTH
#define AF_BTH          32
#endif

#ifndef BTHPROTO_RFCOMM
#define BTHPROTO_RFCOMM 3
#endif

#ifndef AF_BLUETOOTH
#define AF_BLUETOOTH AF_BTH
#endif

#ifndef BTPROTO_RFCOMM
#define BTPROTO_RFCOMM BTHPROTO_RFCOMM
#endif

typedef int socklen_t;

