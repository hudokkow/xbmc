#pragma once
/*
 *      Copyright (C) 2013-present Team Kodi
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

#include <map>
#include <string>
#include <vector>

#include "interfaces/generic/ILanguageInvoker.h"
#include "threads/CriticalSection.h"
#include "threads/Event.h"

class CPythonInvoker : public ILanguageInvoker
{
public:
  explicit CPythonInvoker(ILanguageInvocationHandler *invocationHandler);
  ~CPythonInvoker() override;

  bool Execute(const std::string &script, const std::vector<std::string> &arguments = std::vector<std::string>()) override;

  bool IsStopping() const override { return m_stop || ILanguageInvoker::IsStopping(); }

  typedef void (*PythonModuleInitialization)();
  
protected:
  // implementation of ILanguageInvoker
  bool execute(const std::string &script, const std::vector<std::string> &arguments) override;
  virtual void executeScript(void *fp, const std::string &script, void *module, void *moduleDict);
  bool stop(bool abort) override;
  void onExecutionFailed() override;

  // custom virtual methods
  virtual std::map<std::string, PythonModuleInitialization> getModules() const;
  virtual const char* getInitializationScript() const;
  virtual void onInitialization();
  // actually a PyObject* but don't wanna draw Python.h include into the header
  virtual void onPythonModuleInitialization(void* moduleDict);
  virtual void onDeinitialization();

  virtual void onSuccess() { }
  virtual void onAbort() { }
  virtual void onError(const std::string &exceptionType = "", const std::string &exceptionValue = "", const std::string &exceptionTraceback = "");

  std::string m_sourceFile;
  CCriticalSection m_critical;

private:
  void initializeModules(const std::map<std::string, PythonModuleInitialization> &modules);
  bool initializeModule(PythonModuleInitialization module);
  void addPath(const std::string& path); // add path in UTF-8 encoding
  void addNativePath(const std::string& path); // add path in system/Python encoding
  void getAddonModuleDeps(const ADDON::AddonPtr& addon, std::set<std::string>& paths);

  std::string m_pythonPath;
  void *m_threadState;
  bool m_stop;
  CEvent m_stoppedEvent;

  static CCriticalSection s_critical;
};
