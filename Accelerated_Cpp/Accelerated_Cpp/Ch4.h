#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <vector>
#include <stdexcept>

using std::vector; using std::string;

template<typename T>
T median( vector<T> );

struct Student_Info {
	string name;
	double midterm, final;
	vector<double> homework;
};

class Ch4
{
public:
	Ch4();
	~Ch4();

	std::istream& read( std::ostream& out, std::istream& in, Student_Info& s );
	std::istream& read_hw( std::ostream& out, std::istream& in, vector<double>& hw );

	double grade( const Student_Info& s );

	void print_squares( int max );
};