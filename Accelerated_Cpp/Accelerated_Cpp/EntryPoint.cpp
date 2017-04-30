// Accelerated_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utility.h"
#include "Ch2.h"
#include "Ch3.h"
#include "Ch4.h"
#include "Ch6.h"
#include "Ch7.h"
#include "Ch8.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <iterator>

void Run_Chapter3();
void Run_Chapter4();
void Run_Chapter6();
void Run_Chapter7();
void Run_Chapter8();

void Test_Chapter8();

int main()
{
	Test_Chapter8();

	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    return 0;
}

bool vec_searcher( vector<int>::iterator begin, vector<int>::iterator end, int value )
{
	while( begin != end )
	{
		vector<int>::iterator mid = begin + ( ( end - begin ) / 2 );

		if( value < *mid )
			end = mid;
		else if( *mid < value )
			begin = mid + 1;
		else if( *mid == value )
			return true;
	}

	return false;
}

void Test_Chapter8()
{
	Ch8 ch;

	vector<int> l, r;

	for( int index = 0; index < 10; index++ )
	{
		l.push_back( index );
		r.push_back( index );
	}

	// ch.print_list( l.begin(), l.end(), cout );

	// cout << ( ch.equal( l.begin(), l.end(), r.begin(), r.end() ) == true ? "yes" : "no" ) << endl;
	// cout << ( ch.find( l.begin(), l.end(), 14 ) != l.end() ? "found" : "not found" ) << endl;

	/*
	ch.print_list( r.begin(), r.end(), cout );

	ch.copy( l.begin(), l.end(), r.begin() );
	
	ch.print_list( r.begin(), r.end(), cout );
	*/
	
	vector<int>::const_iterator sit = ch.search( l.begin(), l.end(), r.begin(), r.end() );

	while( sit != l.end() )
	{
		cout << *sit++ << endl;
	}

	// cout << ( ch.accumulate( l.begin(), l.end(), 10 ) ) << endl;
	/*
	vector<int>::const_iterator pit = ch.partition( l.begin(), l.end(), []( const int& x ) -> bool { return x == 4; } );

	while( pit != l.end() )
	{
		cout << *pit++ << endl;
	}
	*/
}

void Run_Chapter8()
{
	Ch8 ch;

	int x = 5, y = 9;
	
	cout << x << '\t' << y << endl;

	ch.swap( x, y );

	cout << x << '\t' << y << endl;

	vector<int> nums;
	nums.push_back( 1 );
	nums.push_back( 2 );
	nums.push_back( 3 );

	copy( nums.begin(), nums.end(), ostream_iterator<int>( cout, " " ) );

	ch.reverse_bi( nums.begin(), nums.end() );

	cout << endl;

	copy( nums.begin(), nums.end(), ostream_iterator<int>( cout, " " ) );
	
	bool exists = ch.binary_searcher( nums.begin(), nums.end(), 5 );

	cout << endl << ( exists ? "yes" : "no" ) << endl;

	copy( nums.begin(), nums.end(), ostream_iterator<int>( cout, " " ) );
}

void Run_Chapter7()
{
	Ch7 ch;
	
	vector<string> sentence = ch.gen_sentence( ch.read_grammar( cin ) );

	vector<string>::const_iterator it = sentence.begin();
	if( !sentence.empty() )
	{
		cout << *it;
		it++;
	}

	while( it != sentence.end() )
	{
		cout << " " << *it;
		++it;
	}

	cout << endl;

	map<string, vector<int> > xref = ch.xref( cin, Ch7::split );

	for( auto iter = xref.begin(); iter != xref.end(); ++iter )
	{
		cout << iter->first;
		
		for( auto iter : iter->second )
		{
			cout << "\t" << iter;
		}

		cout << endl;
	}
}

void Run_Chapter6()
{
	Ch6 ch;

	string value;

	getline( cin, value );

	cout << ch.is_palendrome( value ) << endl;

	vector<string> parts = ch.split2( value );

	for( vector<string>::const_iterator iter = parts.begin(); iter != parts.end(); iter++ ) 
	{ 
		cout << *iter << endl;
	}

	cout << endl;
}

void Run_Chapter4()
{
	Ch4 chapter;
	
	std::vector<Student_Info> students;
	Student_Info record;
	string::size_type max_len = 0;

	while( chapter.read( std::cout, std::cin, record ) ) {
		max_len = std::max( record.name.length(), max_len );
		students.push_back( record );
	}

	std::sort( students.begin(), students.end(), []( const Student_Info& l, const Student_Info& r ) -> bool {
		return l.name < r.name;
	});

	std::cout << std::endl;

	for( std::string::size_type index = 0; index != students.size(); ++index )
	{
		std::cout << students[ index ].name << std::string( max_len + 1 - students[ index ].name.size(), ' ' );

		try
		{
			double final_grade = chapter.grade( students[ index ] );

			std::streamsize perc = std::cout.precision();

			std::cout << std::setprecision( 3 ) << final_grade
				<< std::setprecision( perc )
					<< std::endl;
		}
		catch( std::domain_error e ) {
			std::cout << e.what();
		}
	}
}

void Run_Chapter3()
{
	Ch3 chapter;

	char input[ 255 ];

	std::cin.getline( input, 255 );

	size_t longest, shortest;

	std::tie( longest, shortest ) = chapter.getLongestShortest( std::string( input ) );

	std::cout << longest << " " << shortest << std::endl;
}