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

#include "WindowDialog.h"

#include "ServiceBroker.h"
#include "guilib/GUIComponent.h"
#include "guilib/GUIWindow.h"
#include "guilib/GUIWindowManager.h"
#include "WindowInterceptor.h"

namespace XBMCAddon
{
  namespace xbmcgui
  {
    WindowDialog::WindowDialog() :
      Window(true), WindowDialogMixin(this)
    {
      CSingleLock lock(CServiceBroker::GetWinSystem()->GetGfxContext());
      InterceptorBase* interceptor = new Interceptor<CGUIWindow>("CGUIWindow", this, getNextAvailableWindowId());
      // set the render order to the dialog's default because this dialog is mapped to CGUIWindow instead of CGUIDialog
      interceptor->SetRenderOrder(RENDER_ORDER_DIALOG);
      setWindow(interceptor);
    }

    WindowDialog::~WindowDialog() { deallocating(); }

    bool WindowDialog::OnMessage(CGUIMessage& message)
    {
#ifdef ENABLE_XBMC_TRACE_API
      XBMC_TRACE;
      CLog::Log(LOGDEBUG,"%sNEWADDON WindowDialog::OnMessage Message %d", _tg.getSpaces(),message.GetMessage());
#endif

      switch(message.GetMessage())
      {
      case GUI_MSG_WINDOW_INIT:
        {
          ref(window)->OnMessage(message);
          return true;
        }
        break;

      case GUI_MSG_CLICKED:
        {
          return Window::OnMessage(message);
        }
        break;
      }

      // we do not message CGUIPythonWindow here..
      return ref(window)->OnMessage(message);
    }

    bool WindowDialog::OnAction(const CAction &action)
    {
      XBMC_TRACE;
      return WindowDialogMixin::OnAction(action) ? true : Window::OnAction(action);
    }

    void WindowDialog::OnDeinitWindow(int nextWindowID)
    {
      CServiceBroker::GetGUI()->GetWindowManager().RemoveDialog(iWindowId);
      Window::OnDeinitWindow(nextWindowID);
    }

  }
}
