#pragma once

#include <boost/any.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using boost::any_cast;

struct MyValue
{
	MyValue( int n ) : value( n ) { }
	
	int get() const { return value; }

	int value;
};

class Any
{
public:
	Any();
	~Any();

	void DoAny();
	void AnyError();
	void Swap();
};

template<typename T>
bool is_type( boost::any& any )
{
	return !any.empty() && boost::any_cast<T>( &any );
}