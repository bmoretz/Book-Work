#include "stdafx.h"
#include "Ch7.h"


Ch7::Ch7()
{
}


Ch7::~Ch7()
{
}

void Ch7::countWords()
{
	string line;

	map<string, int> lines;

	while( getline( cin, line ) ) {

		if( line.empty() )
			break;

		++lines[ line ];
	}

	for( map<string, int>::const_iterator iter = lines.begin(); iter != lines.end(); iter++ )
	{
		pair<string, int> element = *iter;

		element.first = "test";

		cout << element.first << '\t' << element.second << endl;
	}
}

vector<string> Ch7::split( const string& input )
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

map<string, vector<int> > Ch7::xref( istream& in, 
	vector<string> find_words( const string& ) = split )
{
	map<string, vector<int> > ret;

	int line_number = 0;
	string line;

	while( getline( in, line ) ) {
		++line_number;

		if( line == "quit" )
			break;

		vector<string> words = find_words( line );

		for( auto iter = words.begin(); iter != words.end(); ++iter )
		{
			ret[ *iter ].push_back( line_number );
		}
	}

	return ret;
}

Grammar Ch7::read_grammar( istream& in )
{
	Grammar ret;
	string line;

	while( getline( in, line ) )
	{
		vector<string> entry = Ch7::split( line );

		if( !entry.empty() )
		{
			ret[ entry[ 0 ] ].push_back( Rule( entry.begin() + 1, entry.end() ) );
		}
	}

	return ret;
}

bool Ch7::bracketed( const string& s )
{
	return s.size() > 1 && s.at( 1 ) == '<' && s.at( s.size() - 1 ) == '>';
}

vector<string> Ch7::gen_sentence( const Grammar& g )
{
	vector<string> ret;

	gen_aux( g, "<sentence>", ret );

	return ret;
}

void Ch7::gen_aux( const Grammar& g, const string& word, vector<string>& ret )
{
	if( !bracketed( word ) )
	{
		ret.push_back( word );
	}
	else
	{
		Grammar::const_iterator it = g.find( word );

		if( it == g.end() )
			throw logic_error( "empty rule" );

		const Rule_Collection& c = it->second;

		const Rule& r = c[ nrand( c.size() ) ];

		for( Rule::const_iterator i = r.begin(); i != r.end(); ++i )
		{
			gen_aux( g, *i, ret );
		}
	}
}

int Ch7::nrand( int n )
{
	if( n <= 0 || n > RAND_MAX )
		throw domain_error( "Argument to nrand is out of range" );

	const int bucket_size = RAND_MAX / n;
	int r;

	do
	{
		r = rand() / bucket_size;
	} while( r >= n );

	return r;
}