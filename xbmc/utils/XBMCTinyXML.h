#pragma once

/*
 *      Copyright (C) 2005-present Team Kodi
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

#ifndef TARGET_WINDOWS
//compile fix for TinyXml < 2.6.0
#define DOCUMENT    TINYXML_DOCUMENT
#define ELEMENT     TINYXML_ELEMENT
#define COMMENT     TINYXML_COMMENT
#define UNKNOWN     TINYXML_UNKNOWN
#define TEXT        TINYXML_TEXT
#define DECLARATION TINYXML_DECLARATION
#define TYPECOUNT   TINYXML_TYPECOUNT
#endif

#include <tinyxml.h>
#include <string>

#undef DOCUMENT
#undef ELEMENT
#undef COMMENT
#undef UNKNOWN
//#undef TEXT
#undef DECLARATION
#undef TYPECOUNT

class CXBMCTinyXML : public TiXmlDocument
{
public:
  CXBMCTinyXML();
  explicit CXBMCTinyXML(const char*);
  explicit CXBMCTinyXML(const std::string& documentName);
  CXBMCTinyXML(const std::string& documentName, const std::string& documentCharset);
  bool LoadFile(TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);
  bool LoadFile(const char*, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);
  bool LoadFile(const std::string& _filename, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);
  bool LoadFile(const std::string& _filename, const std::string& documentCharset);
  bool LoadFile(FILE*, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);
  bool SaveFile(const char*) const;
  bool SaveFile(const std::string& filename) const;
  bool Parse(const std::string& data, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);
  bool Parse(const std::string& data, const std::string& dataCharset);
  inline std::string GetSuggestedCharset(void) const { return m_SuggestedCharset; }
  inline std::string GetUsedCharset(void) const      { return m_UsedCharset; }
  static bool Test();
protected:
  using TiXmlDocument::Parse;
  bool TryParse(const std::string& data, const std::string& tryDataCharset);
  bool InternalParse(const std::string& rawdata, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);

  std::string m_SuggestedCharset;
  std::string m_UsedCharset;
};
