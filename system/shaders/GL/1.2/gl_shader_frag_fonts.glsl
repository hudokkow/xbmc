/*
 *      Copyright (C) 2010-present Team Kodi
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

#version 120

uniform sampler2D m_samp0;
varying vec4 m_cord0;
varying vec4 m_colour;

// SM_FONTS shader
void main ()
{
  gl_FragColor.r   = m_colour.r;
  gl_FragColor.g   = m_colour.g;
  gl_FragColor.b   = m_colour.b;
  gl_FragColor.a   = m_colour.a * texture2D(m_samp0, m_cord0.xy).r;
}
