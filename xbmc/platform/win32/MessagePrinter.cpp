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

#include "platform/MessagePrinter.h"
#include "CompileInfo.h"
#include "platform/win32/CharsetConverter.h"

#include <windows.h>

void CMessagePrinter::DisplayMessage(const std::string& message)
{
  using KODI::PLATFORM::WINDOWS::ToW;
  MessageBox(nullptr, ToW(message).c_str(), ToW(CCompileInfo::GetAppName()).c_str(), MB_OK | MB_ICONINFORMATION);
}

void CMessagePrinter::DisplayWarning(const std::string& warning)
{
  using KODI::PLATFORM::WINDOWS::ToW;
  MessageBox(nullptr, ToW(warning).c_str(), ToW(CCompileInfo::GetAppName()).c_str(), MB_OK | MB_ICONWARNING);
}

void CMessagePrinter::DisplayError(const std::string& error)
{
  using KODI::PLATFORM::WINDOWS::ToW;
  MessageBox(nullptr, ToW(error).c_str(), ToW(CCompileInfo::GetAppName()).c_str(), MB_OK | MB_ICONERROR);
}

void CMessagePrinter::DisplayHelpMessage(const std::vector<std::pair<std::string, std::string>>& help)
{
  using KODI::PLATFORM::WINDOWS::ToW;
  //very crude implementation, pretty it up when possible
  std::string message;
  for (const auto& line : help)
  {
    message.append(line.first + "\t" + line.second + "\r\n");
  }

  MessageBox(nullptr, ToW(message).c_str(), ToW(CCompileInfo::GetAppName()).c_str(), MB_OK | MB_ICONINFORMATION);
}