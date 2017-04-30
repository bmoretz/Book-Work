#include "stdafx.h"
#include "Any.h"

using namespace std;

Any::Any()
{
}


Any::~Any()
{
}

void Any::DoAny()
{
	boost::any v1, v2, v3, v4;

	assert( v1.empty() );

	const char * hello = "Hello";

	v1 = hello;
	v2 = 42;
	v3 = std::string( "Hola" );

	MyValue m1( 10 );

	v4 = m1;

	try
	{
		cout << any_cast< const char* >( v1 ) << endl;
		cout << any_cast< int >( v2 ) << endl;
		cout << any_cast< string >( v3 ) << endl;

		auto x = any_cast< MyValue >( v4 );

		cout << x.get() << endl;
	}
	catch( std::exception & e )
	{
		cout << e.what() << '\n';
	}
}

void Any::AnyError()
{
	boost::any v1, v2;

	v1 = 42;
	v2 = string( "Hello" );

	try
	{
		string *str = boost::any_cast< string * >( v1 );
		assert( str == nullptr );

		int *num = boost::any_cast< int* >( v2 );
		assert( num == nullptr );

		num = boost::any_cast< int >( &v1 );
		str = boost::any_cast< string >( &v2 );
	}
	catch( std::exception & e )
	{
		cout << e.what();
	}
}

void Any::Swap()
{
	boost::any v1 = 19937;
	boost::any v2 = string( "Hello" );

	cout << boost::any_cast< int >( &v1 ) << endl;

	assert( boost::any_cast< int >( &v1 ) != nullptr );
	assert( boost::any_cast< string >( &v2 ) != nullptr );

	v1 = 22.36;
	cout << boost::any_cast< int >( &v1 ) << endl;
	v1.swap( v2 );
	cout << boost::any_cast< int >( &v1 ) << endl;

	assert( boost::any_cast< string >( &v1 ) != nullptr );
	assert( boost::any_cast< double >( &v2 ) != nullptr );

	if( v1.type().hash_code() == typeid( int ).hash_code() ) {
		cout << "v1 == int";
	}
}