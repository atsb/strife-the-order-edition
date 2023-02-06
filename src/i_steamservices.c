//
// Copyright(C) 2016 Night Dive Studios, Inc.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION: Steam platform services implementation
// AUTHORS: James Haley, Samuel Villarreal
//

#ifdef _USE_STEAM_

#include "i_social.h"

static int I_SteamOverlayEventFilter(unsigned int event)
{
    // we do not need to filter any events for the Steam overlay;
    // it absorbs input properly in all cases we don't already deal with.
    return 0;
}

static int I_SteamOverlayEatsShiftTab(void)
{
    // Shift+Tab is handled properly in Steam, nothing special is needed.
    return 0;
}

IAppServices SteamAppServices =
{
    0
};

#endif

// EOF

