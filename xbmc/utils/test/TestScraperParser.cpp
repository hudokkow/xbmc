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

#include "utils/ScraperParser.h"

#include "test/TestUtils.h"

#include "gtest/gtest.h"

TEST(TestScraperParser, General)
{
  CScraperParser a;

  a.Clear();
  EXPECT_TRUE(
    a.Load(XBMC_REF_FILE_PATH("/addons/metadata.themoviedb.org/tmdb.xml")));

  EXPECT_STREQ(
    XBMC_REF_FILE_PATH("/addons/metadata.themoviedb.org/tmdb.xml").c_str(),
    a.GetFilename().c_str());
  EXPECT_STREQ("UTF-8", a.GetSearchStringEncoding().c_str());
}
