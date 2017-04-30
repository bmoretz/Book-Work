// Chapter10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#include <fstream>
#include <istream>
#include <iostream>

using namespace std;

// Function pointer declarations 
typedef double( *analysis_fp )( const int& );

double analysis( const int& x )
{
	return ( ( double ) x / 2 );
}

analysis_fp get_analysis_ptr()
{
	return *analysis;
}

// alternate syntax instead of the typedef
double( *analyis_fp2 )( const int& x );

int next( int n )
{
	return n + 1;
}

size_t my_strlen( const char * str )
{
	size_t len = 0;

	while( *str++ ) {
		len++;
	}

	return len;
}

string letter_grade( double grade )
{
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	static const size_t ngrades = sizeof( numbers ) / sizeof( *numbers );

	for( size_t i = 0; i < ngrades; ++i ) {
		if( grade >= numbers[ i ] ) {
			return letters[ i ];
		}
	}

	return "?\?\?";
}

void do_array()
{
	const char *szLiteral = "this is an array";

	int offset = 0;

	while( *( szLiteral + offset ) )
	{
		cout << *( szLiteral + offset );

		offset++;
	}

	cout << endl << "literal length: " << my_strlen( szLiteral ) << endl;

	const size_t NDim = 3;

	double coords[ NDim ];

	for( size_t index = 0; index < NDim; index++ )
	{
		*( coords + index ) = index;
	}

	ptrdiff_t d = ( *coords + 2 ) - ( *coords );
	double m = ( *coords + NDim );

	cout << endl << "Grade: " << letter_grade( 96 );
}

void do_funcPtr()
{
	int x = 5;

	int( *fp )( int ) = &next;
	int *p = &x;


	// *p "points to" x
	cout << "x = " << x << endl;

	// dereference function pointer "fp", and invoke it with a copy of x.
	// the copy of x will be past to the "next" function, which will return the copy of x value and increment it.
	*p = ( *fp ) ( x );

	cout << "x = " << x << endl;
	// ( *fp ) is dereferencing the "fp" function pointer, and it's equivalent to "fp"
	*p = fp( x );

	cout << "x = " << x << endl;

	// We declared a type for a function that takes a pointer to an integer and returns a double, "analysis_fp" is of this type.
	analysis_fp func = get_analysis_ptr();

	int base = 3;

	// here, we dereference the function pointer and invoke it. The ( *ptr ) dereferencing syntax here is optional. func( v ) works the same.
	double val = ( *func )( base );

	analyis_fp2 = get_analysis_ptr();

	// Alternativly, we could have used the following syntax without the typedef.
	double val2 = ( *analyis_fp2 )( base );
}


void basic_parse( int arg_c, char *arg_v[] )
{
	// Parse cmd line arguments

	// first argument is always current executing binary
	cout << *arg_v << endl;

	// are there any additional arguments?
	if( arg_c > 1 )
	{
		// print first argument (element 1)
		cout << *( arg_v + 1 );

		// print the rest with spaces in between
		for( int index = 2; index < arg_c; index++ )
		{
			cout << " " << *( arg_v + index );
		}

		cout << endl;
	}
}

void parse_files( int arg_c, char **arg_v )
{
	if( arg_c > 1 )
	{
		for( int index = 1; index < arg_c; index++ )
		{
			try
			{
				string file = string( *( arg_v + index ) );

				ifstream in( file.c_str() );

				if( in ) {
					string line;
					while( getline( in, line ) )
					{
						cout << line << endl;
					}
				}
				else {
					cerr << "failed to open file: " << file << endl;
				}
			}
			catch( exception& e )
			{
				cout << e.what();
			}
		}
	}
}

// define one integer, and one pointer to said integer. Change the value of the integer via the pointer reference.
int main( int arg_c, char **arg_v )
{
	//basic_parse( arg_c, arg_v );
	parse_files( arg_c, arg_v );

	do_funcPtr();
	do_array();

	cin.get();

	cout << "Press any key to contine..." << endl;
	return 0;
}