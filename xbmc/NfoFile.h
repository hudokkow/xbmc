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
// NfoFile.h: interface for the CNfoFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NfoFile_H__641CCF68_6D2A_426E_9204_C0E4BEF12D00__INCLUDED_)
#define AFX_NfoFile_H__641CCF68_6D2A_426E_9204_C0E4BEF12D00__INCLUDED_

#pragma once
#include <string>

#include "addons/Scraper.h"
#include "InfoScanner.h"

class CNfoFile
{
public:
  CNfoFile() : m_headPos(0), m_type(ADDON::ADDON_UNKNOWN) {}
  virtual ~CNfoFile() { Close(); }

  CInfoScanner::INFO_TYPE Create(const std::string&,
                                 const ADDON::ScraperPtr&, int episode=-1);
  template<class T>
    bool GetDetails(T& details, const char* document=NULL,
                    bool prioritise=false)
  {
    CXBMCTinyXML doc;
    if (document)
      doc.Parse(document, TIXML_ENCODING_UNKNOWN);
    else if (m_headPos < m_doc.size())
      doc.Parse(m_doc.substr(m_headPos), TIXML_ENCODING_UNKNOWN);
    else
      return false;

    return details.Load(doc.RootElement(), true, prioritise);
  }

  void Close();
  void SetScraperInfo(ADDON::ScraperPtr info) { m_info = info; }
  ADDON::ScraperPtr GetScraperInfo() { return m_info; }
  const CScraperUrl &ScraperUrl() const { return m_scurl; }

  static int Scrape(ADDON::ScraperPtr& scraper, CScraperUrl& url,
                    const std::string& content);

  static std::vector<ADDON::ScraperPtr> GetScrapers(ADDON::TYPE type,
                                                    ADDON::ScraperPtr selectedScraper);

private:
  std::string m_doc;
  size_t m_headPos;
  ADDON::ScraperPtr m_info;
  ADDON::TYPE m_type;
  CScraperUrl m_scurl;

  int Load(const std::string&);
};

#endif // !defined(AFX_NfoFile_H__641CCF68_6D2A_426E_9204_C0E4BEF12D00__INCLUDED_)
