#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <sstream>

class Ch3
{

public:

	Ch3();
	~Ch3();

	void StudentGrades();

	void Quartiles();

	template <typename T>
	std::tuple<T,T,T> get_quartiles( std::vector<T> vals );

	int getDistinctWords( std::string input );
	std::tuple<size_t,size_t> getLongestShortest( std::string input );
};

