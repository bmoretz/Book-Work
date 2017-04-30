// stdafx.cpp : source file that includes just the standard includes
// Chapter9.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#ifdef _DEBUG

bool _trace( TCHAR *format, ... )
{
	TCHAR buffer[ 1000 ];

	va_list argptr;
	va_start( argptr, format );
	wvsprintf( buffer, format, argptr );
	va_end( argptr );

	OutputDebugString( buffer );

	return true;
}

#endif