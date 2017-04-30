#include "stdafx.h"
#include "Utility.h"

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
