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

#pragma once

#include <stdint.h>

namespace XFILE
{

/* indicate that caller can handle truncated reads, where function returns before entire buffer has been filled */
  static const unsigned int READ_TRUNCATED = 0x01;

/* indicate that that caller support read in the minimum defined chunk size, this disables internal cache then */
  static const unsigned int READ_CHUNKED = 0x02;

/* use cache to access this file */
  static const unsigned int READ_CACHED = 0x04;

/* open without caching. regardless to file type. */
  static const unsigned int READ_NO_CACHE = 0x08;

/* calculate bitrate for file while reading */
  static const unsigned int READ_BITRATE = 0x10;

/* indicate to the caller we will seek between multiple streams in the file frequently */
  static const unsigned int READ_MULTI_STREAM = 0x20;

/* indicate to the caller file is audio and/or video (and e.g. may grow) */
  static const unsigned int READ_AUDIO_VIDEO = 0x40;

/* indicate that caller will do write operations before reading  */
  static const unsigned int READ_AFTER_WRITE = 0x80;

/* indicate that caller want to reopen a file if its already open  */
  static const unsigned int READ_REOPEN = 0x100;

struct SNativeIoControl
{
  unsigned long int   request;
  void*               param;
};

struct SCacheStatus
{
  uint64_t forward;  /**< number of bytes cached forward of current position */
  unsigned maxrate;  /**< maximum number of bytes per second cache is allowed to fill */
  unsigned currate;  /**< average read rate from source file since last position change */
  float    level;    /**< cache level (0.0 - 1.0) */
};

typedef enum {
  IOCTRL_NATIVE        = 1,  /**< SNativeIoControl structure, containing what should be passed to native ioctrl */
  IOCTRL_SEEK_POSSIBLE = 2,  /**< return 0 if known not to work, 1 if it should work */
  IOCTRL_CACHE_STATUS  = 3,  /**< SCacheStatus structure */
  IOCTRL_CACHE_SETRATE = 4,  /**< unsigned int with speed limit for caching in bytes per second */
  IOCTRL_SET_CACHE     = 8,  /**< CFileCache */
  IOCTRL_SET_RETRY     = 16, /**< Enable/disable retry within the protocol handler (if supported) */
} EIoControl;

enum CURLOPTIONTYPE
{
  CURL_OPTION_OPTION,     /**< Set a general option   */
  CURL_OPTION_PROTOCOL,   /**< Set a protocol option (see below)  */
  CURL_OPTION_CREDENTIALS,/**< Set User and password  */
  CURL_OPTION_HEADER      /**< Add a Header           */
};

/**
 * The following names for CURL_OPTION_PROTOCOL are possible:
 *
 * accept-charset: Set the "accept-charset" header
 * acceptencoding or encoding: Set the "accept-encoding" header
 * active-remote: Set the "active-remote" header
 * auth: Set the authentication method. Possible values: any, anysafe, digest, ntlm
 * connection-timeout: Set the connection timeout in seconds
 * cookie: Set the "cookie" header
 * customrequest: Set a custom HTTP request like DELETE
 * noshout: Set to true if kodi detects a stream as shoutcast by mistake.
 * postdata: Set the post body (value needs to be base64 encoded). (Implicitly sets the request to POST)
 * referer: Set the "referer" header
 * user-agent: Set the "user-agent" header
 * seekable: Set the stream seekable. 1: enable, 0: disable
 * sslcipherlist: Set list of accepted SSL ciphers.
 */

enum FileProperty
{
  FILE_PROPERTY_RESPONSE_PROTOCOL,          /**< Get response protocol line  */
  FILE_PROPERTY_RESPONSE_HEADER,            /**< Get response Header value  */
  FILE_PROPERTY_CONTENT_TYPE,               /**< Get file content-type  */
  FILE_PROPERTY_CONTENT_CHARSET,            /**< Get file content charset  */
  FILE_PROPERTY_MIME_TYPE,                  /**< Get file mime type  */
  FILE_PROPERTY_EFFECTIVE_URL               /**< Get effective URL for redirected streams  */
};

}
