// Chapter9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

#include "Student_Info.h"

using namespace std;

void display_student( const Student_Info& s )
{
	std::string grade = std::to_string( s.grade() );

	std::cout << "* " << "Name: " << ( s.name() ) << " *" << std::endl;
	std::cout << "* " << "Grade: " << grade << " *" << std::endl;
}

int main()
{

	vector<Student_Info> students;
	string::size_type maxlen = 0;

	Student_Info current;

	while( current.load( cout, cin ) )
	{
		if( current.is_valid() )
		{
			maxlen = max( maxlen, current.name().size() );
			students.push_back( current );
		}
		else
		{
			std::cout << "invalid student data";
		}
	}

	string border = string( maxlen + 4, '*' );

	cout << border;

	for( vector<Student_Info>::size_type index = 0; 
		index < students.size(); index++ )
	{
		display_student( students.at( index ) );
	}

	cout << border;

	cin.ignore();

	cout << std::endl << "Press any key" << std::endl;
	cin.ignore();
	string temp;
	cin >> temp;

	return 0;
}
