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

#define REPLAY_GAIN_NO_PEAK -1.0f
#define REPLAY_GAIN_NO_GAIN -1000.0f

class ReplayGain
{
public:
  enum Type {
    NONE = 0,
    ALBUM,
    TRACK
  };
public:
  class Info
  {
  public:
    Info();
    void SetGain(float aGain);
    void SetGain(const std::string& aStrGain);
    float Gain() const;
    void SetPeak(const std::string& aStrPeak);
    void SetPeak(float aPeak);
    float Peak() const;
    bool HasGain() const;
    bool HasPeak() const;
    bool Valid() const;
  private:
    float m_gain;   // measured in milliBels
    float m_peak;   // 1.0 == full digital scale
  };
  const Info& Get(Type aType) const;
  void Set(Type aType, const Info& aInfo);
  void ParseGain(Type aType, const std::string& aStrGain);
  void SetGain(Type aType, float aGain);
  void ParsePeak(Type aType, const std::string& aStrPeak);
  void SetPeak(Type aType, float aPeak);
  std::string Get() const;
  void Set(const std::string& strReplayGain);
private:
  Info m_data[TRACK];
};
