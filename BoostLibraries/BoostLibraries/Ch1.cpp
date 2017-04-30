#include "stdafx.h"
#include "Ch1.h"

Ch1::Ch1()
{
}

Ch1::~Ch1()
{
}

void Ch1::CheckFile()
{
	cout << "Please enter a file to check:" << endl;

	string file;
	cin >> file;

	boostfs::path p( file );

	if ( boostfs::exists( p ) )
	{
		cout << "File " << p << " exists." << endl;
	}
	else
	{
		cout << "File " << p << " does not exist." << '\n';
	}

	cin.ignore();
}