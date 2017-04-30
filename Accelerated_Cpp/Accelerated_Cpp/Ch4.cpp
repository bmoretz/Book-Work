#include "stdafx.h"
#include "Ch4.h"


Ch4::Ch4()
{
}


Ch4::~Ch4()
{
}

double Ch4::grade( const Student_Info& s )
{
	if( s.homework.size() == 0 )
		throw std::domain_error( "Student has done no homework!" );

	return ( s.final * .4 ) + ( s.midterm * .4 ) + ( median( s.homework ) * .2 );
}

template<typename T>
T median( vector<T> vals )
{
	typedef vector<T>::size_type vec_size;
	std::sort( vals.begin(), vals.end() );

	vec_size length = vals.size();

	if( length == 0 )
		throw std::domain_error( "Length can't be zero!" );

	T middle = length / 2;

	T median = length % 2 == 0 ?
		( vals[ middle ] + vals[ middle + 1 ] ) / 2

		: vals[ middle ];

	return median;
}

std::istream& Ch4::read( std::ostream& out, std::istream& in, Student_Info& s )
{
	out << "Enter name: ";
	in >> s.name;

	out << "Enter midterm: ";
	in >> s.midterm;

	std::cout << "Enter final: ";
	in >> s.final;

	read_hw( out, in, s.homework );
	
	return in;
}

std::istream& Ch4::read_hw( std::ostream& out, std::istream& in, std::vector<double>& hw )
{
	if( in )
	{
		hw.clear();

		double x;
		
		out << "Enter homework: ";

		while( in >> x ) {
			out << "Enter homework: ";
			hw.push_back( x );
		}

		in.clear();
	}

	return in;
}

void Ch4::print_squares( int max )
{
	
	for( int index = 0; index < max; index++ )
	{

	}
}
