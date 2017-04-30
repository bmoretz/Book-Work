#pragma once

#include <assert.h>>

#include <string>
#include <vector>
#include <istream>
#include <numeric>
#include <iostream>

class Student_Info
{

public:
	Student_Info();
	Student_Info( const Student_Info& );
	Student_Info( std::ostream& out, std::istream& );

	~Student_Info();
	
	bool is_valid() const { return !m_homework.empty(); };
	std::string name() const { return m_name; };
	double grade() const;

	std::istream& load( std::ostream&, std::istream& );
private:
	
	std::string m_name;
	double m_midterm, m_final;
	std::vector<double> m_homework;
};

bool compare( const Student_Info&, const Student_Info& );
