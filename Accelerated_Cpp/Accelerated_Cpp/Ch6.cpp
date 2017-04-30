#include "stdafx.h"
#include "Ch6.h"


Ch6::Ch6()
{
}


Ch6::~Ch6()
{
}

vector<string> Ch6::split( const string& input )
{
	vector<string> result;

	string working;

	for( string::const_iterator iter = input.begin(); iter != input.end(); iter++ )
	{
		if( isspace( *iter ) )
		{
			result.push_back( working );
			working = string();
		}
		else
		{
			working.push_back( *iter );
		}
	}

	result.push_back( working );
	
	return result;
}

vector<string> Ch6::split2( const string & input )
{
	vector<string> result;
	string::const_iterator curr = input.begin();

	while( curr != input.end() )
	{
		curr = find_if( curr, input.end(), [] ( const char c ) -> bool { return !isspace( c ); } );

		string::const_iterator next = find_if( curr, input.end(), [] ( const char c ) -> bool { return isspace(c); } );

		if( curr != input.end() )
			result.push_back( string( curr,next ) );

		curr = next;
	}

	return result;
}

bool Ch6::is_palendrome( const string & input )
{
	return equal( input.begin(), input.end(), input.rbegin() );
}

vector<string> Ch6::find_urls( const string & input )
{
	vector<string> result;

	typedef string::const_iterator iter;
	
	iter b = input.begin(), e = input.end();

	while( b != e )
	{
		b = url_beg( b, e );

		if( b != e )
		{
			iter after = url_end( b, e );

			result.push_back( string( b, after ) );

			b = after;
		}
	}

	return result;
}

bool not_url_char( char c )
{
	static const string url_ch = "~;/?:@=&$-_.+~*'(),";

	return !( isalnum( c ) || find( url_ch.begin(), url_ch.end(), c ) != url_ch.end() );
}

string::const_iterator
Ch6::url_end( string::const_iterator b, string::const_iterator e )
{
	return find_if
	(
		b, e,
		not_url_char
	);
}

string::const_iterator
Ch6::url_beg( string::const_iterator b, string::const_iterator e )
{
	static const string sep = "://";

	typedef string::const_iterator iter;

	iter i = b;

	while( ( i = search( i, e, sep.begin(), sep.end() ) ) != e )
	{
		if( i != b && i + sep.size() != e )
		{
			iter beg = i;

			while( beg != b && isalpha( beg[ -1 ] ) )
			{
				beg--;
			}

			if( beg != i && !not_url_char( i[ sep.size() ] ) )
			{
				return beg;
			}

			i += sep.size();
		}
	}

	return e;
}

double Ch6::average( const vector<double>& v )
{
	return accumulate( v.begin(), v.end(), 0.0 ) / v.size();
}