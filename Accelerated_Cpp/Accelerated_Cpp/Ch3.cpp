#include "stdafx.h"
#include "Ch3.h"

Ch3::Ch3()
{}


Ch3::~Ch3()
{}

void Ch3::StudentGrades()
{
	std::cout << "Please enter your midterm and final grades: " << std::endl;

	double midterm, exam;
	
	std::cin >> midterm >> exam;

	std::cout << "Please enter your homework grades: " << std::endl;

	std::vector<double> homework;

	double hw;

	while( std::cin >> hw ) {
			homework.push_back( hw );
	}
	
	typedef std::vector<double>::size_type vec_size;

	vec_size grades = homework.size();

	std::sort( homework.begin(), homework.end() );

	vec_size mid = grades / 2;

	double median;

	median = grades % 2 == 0 ? 
		( homework[ mid ] + homework[ mid - 1 ] ) / 2 
		: homework[ mid ];

	std::streamsize prec = std::cout.precision();
	
	std::cout << "your final grade is: " << std::setprecision( 3 )
		<< 0.2 * midterm + 0.4 * exam + .4 * median
		<< std::setprecision( prec )
	;
}

void Ch3::Quartiles()
{
	std::vector<int> v = std::vector<int>();
	
	int data[ 11 ] = { 6, 7, 15, 36, 39, 40, 41, 42, 43, 47, 49 };
	
	for( int index = 0; index < 11; index++ )
		v.push_back( data[ index ] );

	int q1, q2, q3;

	std::tie( q1, q2, q3 ) = get_quartiles( v );
		
	std::cout << q1 << " " << q2 << " " << q3 << std::endl;
}

template <typename T>
std::tuple<T,T,T> Ch3::get_quartiles( std::vector<T> vals )
{
	std::sort( vals.begin(), vals.end() );
	typedef std::vector<T>::size_type vec_size;

	vec_size middle = vals.size() / 2;

	std::vector<T> lower, upper;

	for( int start = 0; start < middle; start++ )
	{
		lower.push_back( vals[ start ] );
		upper.push_back( vals[ start + middle + 1 ] );
	}

	T lower_quartile = lower.at( lower.size() / 2 );
	T upper_quartile = upper.at( upper.size() / 2 );
	
	return std::make_tuple( lower_quartile, vals.at( vals.size() / 2 ), upper_quartile );
}

template<typename T>
T median( std::vector<T> vals )
{
	std::sort( vals.begin(), vals.end() );
	typedef std::vector<T>::size_type vec_size;
	vec_size len = vals.size();

	T middle = len / 2;

	T median = middle % 2 == 0 ?
		( vals[ middle ] + vals[ middle - 1 ] ) / 2
		: vals[ middle ];

	return median;
}

template<typename T>
void display( std::vector<T> vals )
{
	for( int index = 0; index < vals.size(); index++ )
	{
		std::cout << vals[ index ] << std::endl;
	}
}

int Ch3::getDistinctWords( std::string input )
{
	std::vector<std::string> words;
	std::string current;

	wchar_t delimiter = ' ';
	
	for( std::string::iterator it = input.begin(); it != input.end(); it++ )
	{
		if( *it == delimiter || it == input.end() )
		{
			if( std::find( words.begin(), words.end(), current ) == words.end() )
				words.push_back( current );

			current = std::string( "" );
		} else {
			current.push_back( *it );
		}
	}

	return words.size();
}

std::tuple<size_t, size_t> Ch3::getLongestShortest( std::string input )
{
	std::vector<std::string> words;
	std::string current;
	wchar_t delimiter = ' ';

	std::stringstream parse( input );

	while( parse >> current )
		words.push_back( current );

	std::sort( words.begin(), words.end(), []( const std::string & l, const std::string & r ) -> bool
	{
		return l.length() < r.length();
	});

	return std::make_tuple<size_t,size_t>( words.at( 0 ).length(), words.at( words.size() - 1 ).length() );
}