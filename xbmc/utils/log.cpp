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

#include "log.h"
#include "CompileInfo.h"
#include "settings/AdvancedSettings.h"
#include "threads/CriticalSection.h"
#include "threads/SingleLock.h"
#include "threads/Thread.h"
#include "utils/StringUtils.h"

#if defined(TARGET_POSIX)
#include "platform/posix/utils/PosixInterfaceForCLog.h"
typedef class CPosixInterfaceForCLog PlatformInterfaceForCLog;
#elif defined(TARGET_WINDOWS)
#include "platform/win32/utils/Win32InterfaceForCLog.h"
typedef class CWin32InterfaceForCLog PlatformInterfaceForCLog;
#endif


static const char* const levelNames[] =
{"DEBUG", "INFO", "NOTICE", "WARNING", "ERROR", "SEVERE", "FATAL", "NONE"};

// add 1 to level number to get index of name
static const char* const logLevelNames[] =
{ "LOG_LEVEL_NONE" /*-1*/, "LOG_LEVEL_NORMAL" /*0*/, "LOG_LEVEL_DEBUG" /*1*/, "LOG_LEVEL_DEBUG_FREEMEM" /*2*/ };

namespace
{
class CLogGlobals
{
public:
  CLogGlobals(void) : m_repeatCount(0), m_repeatLogLevel(-1), m_logLevel(LOG_LEVEL_DEBUG), m_extraLogLevels(0) {}
  ~CLogGlobals() = default;
  PlatformInterfaceForCLog m_platform;
  int         m_repeatCount;
  int         m_repeatLogLevel;
  std::string m_repeatLine;
  int         m_logLevel;
  int         m_extraLogLevels;
  CCriticalSection critSec;
};

static CLogGlobals g_logState;
}

CLog::CLog() = default;

CLog::~CLog() = default;

void CLog::Close()
{
  CSingleLock waitLock(g_logState.critSec);
  g_logState.m_platform.CloseLogFile();
  g_logState.m_repeatLine.clear();
}

void CLog::LogString(int logLevel, std::string&& logString)
{
  CSingleLock waitLock(g_logState.critSec);
  std::string strData(logString);
  StringUtils::TrimRight(strData);
  if (!strData.empty())
  {
    if (g_logState.m_repeatLogLevel == logLevel && g_logState.m_repeatLine == strData)
    {
      g_logState.m_repeatCount++;
      return;
    }
    else if (g_logState.m_repeatCount)
    {
      std::string strData2 = StringUtils::Format("Previous line repeats %d times.",
                                                g_logState.m_repeatCount);
      PrintDebugString(strData2);
      WriteLogString(g_logState.m_repeatLogLevel, strData2);
      g_logState.m_repeatCount = 0;
    }

    g_logState.m_repeatLine = strData;
    g_logState.m_repeatLogLevel = logLevel;

    PrintDebugString(strData);

    WriteLogString(logLevel, strData);
  }
}

void CLog::LogString(int logLevel, int component, std::string&& logString)
{
  if (g_advancedSettings.CanLogComponent(component) && IsLogLevelLogged(logLevel))
    LogString(logLevel, std::move(logString));
}

bool CLog::Init(const std::string& path)
{
  CSingleLock waitLock(g_logState.critSec);

  // the log folder location is initialized in the CAdvancedSettings
  // constructor and changed in CApplication::Create()

  std::string appName = CCompileInfo::GetAppName();
  StringUtils::ToLower(appName);
  return g_logState.m_platform.OpenLogFile(path + appName + ".log", path + appName + ".old.log");
}

void CLog::MemDump(char *pData, int length)
{
  Log(LOGDEBUG, "MEM_DUMP: Dumping from %p", pData);
  for (int i = 0; i < length; i+=16)
  {
    std::string strLine = StringUtils::Format("MEM_DUMP: %04x ", i);
    char *alpha = pData;
    for (int k=0; k < 4 && i + 4*k < length; k++)
    {
      for (int j=0; j < 4 && i + 4*k + j < length; j++)
      {
        std::string strFormat = StringUtils::Format(" %02x", (unsigned char)*pData++);
        strLine += strFormat;
      }
      strLine += " ";
    }
    // pad with spaces
    while (strLine.size() < 13*4 + 16)
      strLine += " ";
    for (int j=0; j < 16 && i + j < length; j++)
    {
      if (*alpha > 31)
        strLine += *alpha;
      else
        strLine += '.';
      alpha++;
    }
    Log(LOGDEBUG, "%s", strLine.c_str());
  }
}

void CLog::SetLogLevel(int level)
{
  CSingleLock waitLock(g_logState.critSec);
  if (level >= LOG_LEVEL_NONE && level <= LOG_LEVEL_MAX)
  {
    g_logState.m_logLevel = level;
    CLog::Log(LOGNOTICE, "Log level changed to \"%s\"", logLevelNames[g_logState.m_logLevel + 1]);
  }
  else
    CLog::Log(LOGERROR, "%s: Invalid log level requested: %d", __FUNCTION__, level);
}

int CLog::GetLogLevel()
{
  return g_logState.m_logLevel;
}

void CLog::SetExtraLogLevels(int level)
{
  CSingleLock waitLock(g_logState.critSec);
  g_logState.m_extraLogLevels = level;
}

bool CLog::IsLogLevelLogged(int loglevel)
{
  const int extras = (loglevel & ~LOGMASK);
  if (extras != 0 && (g_logState.m_extraLogLevels & extras) == 0)
    return false;

  if (g_logState.m_logLevel >= LOG_LEVEL_DEBUG)
    return true;
  if (g_logState.m_logLevel <= LOG_LEVEL_NONE)
    return false;

  // "m_logLevel" is "LOG_LEVEL_NORMAL"
  return (loglevel & LOGMASK) >= LOGNOTICE;
}


void CLog::PrintDebugString(const std::string& line)
{
#if defined(_DEBUG) || defined(PROFILE)
  g_logState.m_platform.PrintDebugString(line);
#endif // defined(_DEBUG) || defined(PROFILE)
}

bool CLog::WriteLogString(int logLevel, const std::string& logString)
{
  static const char* prefixFormat = "%02d:%02d:%02d.%03d T:%" PRIu64" %7s: ";

  std::string strData(logString);
  /* fixup newline alignment, number of spaces should equal prefix length */
  StringUtils::Replace(strData, "\n", "\n                                            ");

  int hour, minute, second;
  double millisecond;
  g_logState.m_platform.GetCurrentLocalTime(hour, minute, second, millisecond);

  strData = StringUtils::Format(prefixFormat,
                                  hour,
                                  minute,
                                  second,
                                  static_cast<int>(millisecond),
                                  (uint64_t)CThread::GetCurrentThreadId(),
                                  levelNames[logLevel]) + strData;

  return g_logState.m_platform.WriteStringToLog(strData);
}
