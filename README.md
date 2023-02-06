Strife: The Order Edition
=======================================

This has been renamed to The Order Edition since 
the Strife: Veteran Edition is a trademarked name by NightDive Studios.

This file contains the following sections:

- GENERAL NOTES
- LICENSE

GENERAL NOTES
=============

Game data and patching:
-----------------------

Strife: The Order Edition uses the Strife Veteran Edition game data.

This source port does not contain any game data of the Strife Veteran Edition, the game data is still
covered by the original EULA and must be obeyed as usual.

Strife: Veteran Edition is available from [GOG](https://www.gog.com/game/strife_veteran_edition)

Strife: Veteran Edition is available from the [Steam store](http://store.steampowered.com/app/317040/)

Compiling on Windows:
---------------------

A cleaned and corrected project file for Microsoft Visual Studio is provided in 
msvc2022/strife-toe.sln and should compile with any edition except in visual studio 2010 or down.
for the x64 users: at the moment libtheora will be the library for playing videos it´s being defined with
`NIGHTDIVE` 

Compiling on Linux and macOS:
-------------------

A CMake build system has been added in version 1.3, and is currently up-to-date.

Trademark disclaimers:
----------------------

The source code itself may make reference to the following trademarks:

"DOOM" is a trademark of ZeniMax Media, Incorporated.
"Heretic" and "Hexen" are trademarks of Raven Software, Incorporated.
"Strife: Veteran Edition" is a trademark of Night Dive Studios, Incorporated.

No license for use or transfer of ownership in any trademark is implied or
should be construed.


Steam, GOG Galaxy, and Nintendo Switch:
---------------------------------------
The Strife: The Order Edition GPL Source Code release does not include 
functionality for integrating with Steam, GOG Galaxy, or Nintendo Switch.
This includes roaming profiles, achievements, leaderboards, matchmaking, the
overlay, or any other Steam or Galaxy features.  It may be necessary to 
undefine the `_USE_STEAM_`, `GOG_RELEASE`, or `SVE_PLAT_SWITCH` symbols in 
build scripts or project files in order to compile.

Due to the integration with steam/gog - Strife: The Order Edition also does not
support any frontend multiplayer and any other such things.


LICENSE
=======

The Strife: The Order Edition source port is available under the terms of the GNU
General Public License v2.0

Exceptions for linking with Steam, GOG Galaxy, and Nintendo Switch runtimes,
which are subject to non-disclosure agreements, were obtained by Night Dive
Studios, Inc. Code subject to NDA it´s not included with this public source 
port.

DISCLAIMER: The authors and contribuitors of this source port, they are not responsable for trying to 
build the referents platforms above, so don´t ask to how to compile
and do not distribute the binnaries of nintendo switch or other platforms above 
this illegal and you will be suffering a lawsuit.

See COPYING.txt for the GNU GENERAL PUBLIC LICENSE


EXCLUDED CODE: The code described below and contained in The Strife: The Order Edition
it´s not part of the Program covered by the GPL 
and is expressly excluded from its terms.  You are solely responsible for 
obtaining from the copyright holder a license for such code and complying with
the applicable license terms.

libogg, libtheora, libvorbis
----------------------------
Copyright (c) 2002-2018 Xiph.org Foundation

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

- Neither the name of the Xiph.org Foundation nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

libpng
-------------------------------------------------------------------------------
libpng version 1.6.12 - June 12, 2014
Copyright (c) 1998-2014 Glenn Randers-Pehrson
 (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)
 (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)

The PNG Reference Library is supplied "AS IS".  The Contributing Authors
and Group 42, Inc. disclaim all warranties, expressed or implied,
including, without limitation, the warranties of merchantability and of
fitness for any purpose.  The Contributing Authors and Group 42, Inc.
assume no liability for direct, indirect, incidental, special, exemplary,
or consequential damages, which may result from the use of the PNG
Reference Library, even if advised of the possibility of such damage.

Permission is hereby granted to use, copy, modify, and distribute this
source code, or portions hereof, for any purpose, without fee, subject
to the following restrictions:

  1. The origin of this source code must not be misrepresented.

  2. Altered versions must be plainly marked as such and must not
     be misrepresented as being the original source.

  3. This Copyright notice may not be removed or altered from
     any source or altered source distribution.

The Contributing Authors and Group 42, Inc. specifically permit, without
fee, and encourage the use of this source code as a component to
supporting the PNG file format in commercial products.  If you use this
source code in a product, acknowledgment is not required but would be
appreciated.

SDL
---
SDL2, SDL2_mixer, and SDL2_net are used under the terms of SDL license:

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

zlib
-------------------------------------------------------------------------------
version 1.2.7, May 2nd, 2012

Copyright (C) 1995-2012 Jean-loup Gailly and Mark Adler

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

-------------------------------------------------------------------------------
