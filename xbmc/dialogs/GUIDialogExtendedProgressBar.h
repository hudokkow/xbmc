#pragma once
/*
 *      Copyright (C) 2012-present Team Kodi
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

#include <string>
#include <vector>

#include "guilib/GUIDialog.h"

class CGUIDialogProgressBarHandle
{
public:
  explicit CGUIDialogProgressBarHandle(const std::string &strTitle) :
    m_fPercentage(0),
    m_strTitle(strTitle),
    m_bFinished(false) {}
  virtual ~CGUIDialogProgressBarHandle(void) = default;

  const std::string &Title(void) { return m_strTitle; }
  void SetTitle(const std::string &strTitle);

  std::string Text(void) const;
  void SetText(const std::string &strText);

  bool IsFinished(void) const { return m_bFinished; }
  void MarkFinished(void)     { m_bFinished = true; }

  float Percentage(void) const          { return m_fPercentage;}
  void SetPercentage(float fPercentage) { m_fPercentage = fPercentage; }
  void SetProgress(int currentItem, int itemCount);

private:
  CCriticalSection  m_critSection;
  float             m_fPercentage;
  std::string       m_strTitle;
  std::string       m_strText;
  bool              m_bFinished;
};

class CGUIDialogExtendedProgressBar : public CGUIDialog
{
public:
  CGUIDialogExtendedProgressBar(void);
  ~CGUIDialogExtendedProgressBar(void) override = default;
  bool OnMessage(CGUIMessage& message) override;
  void Process(unsigned int currentTime, CDirtyRegionList &dirtyregions) override;

  CGUIDialogProgressBarHandle *GetHandle(const std::string &strTitle);

protected:
  void UpdateState(unsigned int currentTime);

  CCriticalSection                           m_critSection;
  unsigned int                               m_iCurrentItem;
  unsigned int                               m_iLastSwitchTime;
  std::vector<CGUIDialogProgressBarHandle *> m_handles;
};
