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

#pragma once

#include "cores/VideoSettings.h"

#include <stdint.h>

class CConvolutionKernel
{
  public:
    CConvolutionKernel(ESCALINGMETHOD method, int size);
    ~CConvolutionKernel();

    int      GetSize()           { return m_size; }
    float*   GetFloatPixels()    { return m_floatpixels; }
    uint8_t* GetIntFractPixels() { return m_intfractpixels; }
    uint8_t* GetUint8Pixels()    { return m_uint8pixels; }

  private:
    CConvolutionKernel(const CConvolutionKernel&) = delete;
    CConvolutionKernel& operator=(const CConvolutionKernel&) = delete;
    void Lanczos2();
    void Lanczos3Fast();
    void Lanczos3();
    void Spline36Fast();
    void Spline36();
    void Bicubic(double B, double C);

    static double LanczosWeight(double x, double radius);
    static double Spline36Weight(double x);
    static double BicubicWeight(double x, double B, double C);

    void ToIntFract();
    void ToUint8();

    int      m_size;
    float*   m_floatpixels;
    uint8_t* m_intfractpixels;
    uint8_t* m_uint8pixels;
};
