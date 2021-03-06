/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Mupen64plus - 7zTypes.h                                               *
 *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
 *   Copyright (C) 2008 Tillin9                                            *
 *   7-Zip Copyright (C) 1999-2007 Igor Pavlov.                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __C_TYPES_H
#define __C_TYPES_H

#include <zconf.h>

#ifndef _7ZIP_UINT16_DEFINED
#define _7ZIP_UINT16_DEFINED
typedef unsigned short UInt16;
#endif 

#ifndef _7ZIP_UINT32_DEFINED
#define _7ZIP_UINT32_DEFINED
#ifdef _LZMA_UINT32_IS_ULONG
typedef unsigned long UInt32;
#else
typedef unsigned int UInt32;
#endif
#endif 

#ifndef _7ZIP_INT32_DEFINED
#define _7ZIP_INT32_DEFINED
#ifdef _LZMA_INT32_IS_ULONG
typedef long Int32;
#else
typedef int Int32;
#endif
#endif 

/* #define _SZ_NO_INT_64 */
/* define it your compiler doesn't support long long int */

#ifndef _7ZIP_UINT64_DEFINED
#define _7ZIP_UINT64_DEFINED
#ifdef _SZ_NO_INT_64
typedef unsigned long UInt64;
#else
#if defined(_MSC_VER) || defined(__BORLANDC__)
typedef unsigned __int64 UInt64;
#else
typedef unsigned long long int UInt64;
#endif
#endif
#endif


/* #define _SZ_FILE_SIZE_32 */
/* You can define _SZ_FILE_SIZE_32, if you don't need support for files larger than 4 GB*/

#ifndef CFileSize
#ifdef _SZ_FILE_SIZE_32
typedef UInt32 CFileSize; 
#else
typedef UInt64 CFileSize; 
#endif
#endif

#define SZ_RESULT int

typedef int HRes;
#define RES_OK (0)

#define SZ_OK (0)
#define SZE_DATA_ERROR (1)
#define SZE_CRC_ERROR (3)
#define SZE_ARCHIVE_ERROR (6)

#define SZE_OUTOFMEMORY (0x8007000E)
#define SZE_NOTIMPL (0x80004001)
#define SZE_FAIL (0x80004005)
#define SZE_INVALIDARG (0x80070057)


#ifndef RINOK
#define RINOK(x) { HRes __result_ = (x); if(__result_ != 0) return __result_; }
#endif

#ifndef Bool
typedef int Bool;
#define True 1
#define False 0
#endif

#ifdef _MSC_VER
#define StdCall __stdcall 
#else
#define StdCall
#endif

#if _MSC_VER >= 1300
#define MY_FAST_CALL __declspec(noinline) __fastcall 
#elif defined( _MSC_VER)
#define MY_FAST_CALL __fastcall 
#else
#define MY_FAST_CALL
#endif

#endif

