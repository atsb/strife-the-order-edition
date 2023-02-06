// Emacs style mode select   -*- C -*-
//-----------------------------------------------------------------------------
//
// Copyright(C) 2022-2023 André Guilherme 
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
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
// 02111-1307, USA.
//
//-----------------------------------------------------------------------------

#include "doomtype.h"

#ifdef _WIN32
#include <io.h>
#ifdef WIP
#include <Windows.h>
#endif
#else
#include <unistd.h>
#include <strings.h>
#endif
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#ifdef OLD_MSVC
#define W32GetVersionEX(lpVersionInformation) GetVersionEx(lpVersionInformation)
#else
#define W32GetVersionEX(lpVersionInformation, wTypeMask, dwlConditionMask) VerifyVersionInfo(lpVersionInformation, wTypeMask, dwlConditionMask)
#define W32OVERSIONINFO LPOSVERSIONINFOEXW
#endif

#ifdef WIP
#ifdef C89 //Adding again because some platforms don´t support stdbool.h

#define false 0
#define true 1
#ifndef _WIN32
typedef unsigned char boolean;
#endif
#else
#include <stdbool.h> //for true and false.
#ifndef _WIN32
typedef unsigned char boolean;
#endif
#endif
#else
#include <stdbool.h>
#endif
#ifdef WIP
#ifdef _WIN32
#ifdef _XBOX
#include <xtl.h>
#include <XObjBase.h>
#include <basetsd.h>
#else
#include <Windows.h>
#include <rpc.h>
#include <rpcndr.h>
#endif
#endif 
#endif
#ifdef PSNPRINTF
#include "psnprntf.h"
#endif

#ifdef _WIN32
#define w3sopen _open
#define w3swrite _write
#define w3saccess _access
#define w3sread _read
#define w3sclose _close
#define w3sstrdup _strdup
#define w3sstrupr _strupr
#define w3sstrcasecmp _stricmp
#define w3sstrncasecmp _strnicmp
#define w3sstrlwr _strlwr
#define w3sputenv _putenv
#define w3smkdir _mkdir
#define DIR_SEPARATOR '\\'
#define PATH_SEPARATOR ';'
#else
#define w3sopen open
#define w3swrite write
#define w3saccess access
#define w3sclose close
#define w3sread read
#define w3sstrdup strdup
char* w3sstrupr(char* str);
char* w3sstrlwr(char* str);
#define w3sstrcasecmp strcasecmp
#define w3sstrncasecmp strncasecmp
#define w3sputenv _putenv
#define w3smkdir mkdir
#define DIR_SEPARATOR '/'
#define PATH_SEPARATOR ':'
#endif

#define w3svsprintf(buf, format, arg) vsprintf(buf, format, arg)

#if defined(CHOCO_VSNPRITNTF)
int w3svsnprintf(char* buf, size_t buf_len, const char* s, va_list args);
#elif defined(PSNPRINTF)
#define w3ssnprintf psnprintf
#define w3svsnprintf pvsnprintf
#else
#if !defined(CHOCO_VSNPRINTF) || defined(PSNPRINTF)
#ifdef _WIN32
#define w3svsnprintf _vsnprintf
#define w3ssnprintf _snprintf
#else
#define w3svsnprintf vsnprintf
#define w3ssnprintf snprintf
#endif
#endif
#endif

int htoi(char* str);
bool fcmp(float f1, float f2);

#if defined __linux__ || defined VITA
#define max(num1, num2) ((num1)>(num2)?(num1):(num2))
#define min(num1, num2) ((num1)<(num2)?(num1):(num2))
#endif

#ifdef C99
#define M_PI 3.14159265358979323846
#endif