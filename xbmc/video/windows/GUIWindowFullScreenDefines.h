/*
 *      Copyright (C) 2017-present Team Kodi
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
#pragma once

#define BLUE_BAR                          0
#define LABEL_ROW1                       10
#define LABEL_ROW2                       11
#define LABEL_ROW3                       12

 // Displays current position, visible after seek or when forced
 // Alt, use conditional visibility Player.DisplayAfterSeek
#define LABEL_CURRENT_TIME               22

 // Displays when video is rebuffering
 // Alt, use conditional visibility Player.IsCaching
#define LABEL_BUFFERING                  24

 // Progressbar used for buffering status and after seeking
#define CONTROL_PROGRESS                 23
