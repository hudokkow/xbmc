#pragma once
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

#include <string>
#include <vector>

typedef enum TextSearchDefault
{
  SEARCH_DEFAULT_AND = 0,
  SEARCH_DEFAULT_OR,
  SEARCH_DEFAULT_NOT
} TextSearchDefault;

class CTextSearch
{
public:
  CTextSearch(const std::string &strSearchTerms, bool bCaseSensitive = false, TextSearchDefault defaultSearchMode = SEARCH_DEFAULT_OR);
  virtual ~CTextSearch(void);

  bool Search(const std::string &strHaystack) const;
  bool IsValid(void) const;

private:
  static void GetAndCutNextTerm(std::string &strSearchTerm, std::string &strNextTerm);
  void ExtractSearchTerms(const std::string &strSearchTerm, TextSearchDefault defaultSearchMode);

  bool                     m_bCaseSensitive;
  std::vector<std::string>  m_AND;
  std::vector<std::string>  m_OR;
  std::vector<std::string>  m_NOT;
};
