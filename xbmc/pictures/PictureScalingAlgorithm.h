#pragma once
/*
 *      Copyright (C) 2015-present Team Kodi
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
#include <map>

class CPictureScalingAlgorithm
{
public:
  typedef enum Algorithm
  {
    NoAlgorithm,
    FastBilinear,
    Bilinear,
    Bicubic,
    Experimental,
    NearestNeighbor,
    AveragingArea,
    Bicublin,
    Gaussian,
    Sinc,
    Lanczos,
    BicubicSpline
  } Algorithm;

  static Algorithm Default;

  static Algorithm FromString(const std::string& scalingAlgorithm);
  static std::string ToString(Algorithm scalingAlgorithm);
  static int ToSwscale(const std::string& scalingAlgorithm);
  static int ToSwscale(Algorithm scalingAlgorithm);

private:
  CPictureScalingAlgorithm();

  typedef struct ScalingAlgorithm
  {
    std::string name;
    int swscale;
  } ScalingAlgorithm;

  typedef std::map<CPictureScalingAlgorithm::Algorithm, CPictureScalingAlgorithm::ScalingAlgorithm> AlgorithmMap;
  static AlgorithmMap m_algorithms;
};
