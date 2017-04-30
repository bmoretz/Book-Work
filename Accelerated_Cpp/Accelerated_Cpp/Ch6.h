#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <vector>
#include <stdexcept>
#include <numeric>

using namespace std;

class Ch6
{
public:
	Ch6();
	~Ch6();

	vector<string> split( const string & input );
	vector<string> split2( const string & intput );
	bool is_palendrome( const string & input );
	
	vector<string> find_urls( const string & input );
	string::const_iterator url_beg( string::const_iterator b, string::const_iterator e );
	string::const_iterator url_end( string::const_iterator b, string::const_iterator e );

	double average( const vector<double>& v );
};

