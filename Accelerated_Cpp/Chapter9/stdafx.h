// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <windows.h>

#ifdef _DEBUG
	bool _trace( TCHAR *format, ... );
#define TRACE _trace
#else
	#define TRACE false && _trace
#endif