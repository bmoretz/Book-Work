// BoostLibraries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Ch1.h"
#include "Ch2.h"
#include "Any.h"

using namespace std;

void UseAny();

int _tmain( int argc, _TCHAR* argv[] )
{
	UseAny();

	cout << endl << "Press ENTER to continue...";
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );

	return 0;
}

void UseAny()
{
	Any example;

	example.DoAny();

	example.AnyError();

	example.Swap();
}
