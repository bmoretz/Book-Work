#include "stdafx.h"
#include "Student_Info.h"

#define TRACE _trace

using namespace std;

#pragma region Global

istream& read_hw( ostream& out, istream& in, vector<double>& vec )
{
	if( in )
	{
		vec.clear();

		double x;
		int number = 0;

		out << "Homework " << ++number << ": ";
		while( in >> x ) {
			vec.push_back( x );
			out << "Homework " << ++number << ": ";
		}

		in.clear();
	}

	return in;
}

// Midterm: 20%, final: 30%, homework: 50%
double grade( double midterm, double final, vector<double> homework )
{
	TRACE( L"midterm: %.2f", midterm );

	double pts_mid = midterm * .20;
	double pts_final = final * .30;
	double pts_hw = ( ( accumulate( homework.begin(), homework.end(), 0.0f ) / homework.size() ) * .50 );

	return pts_mid + pts_final + pts_hw;
}

bool compare( const Student_Info& l, const Student_Info& r )
{
	return l.name() < r.name();
}

#pragma endregion

#pragma region Constructor

Student_Info::Student_Info()
	: m_midterm( 0 ), m_final( 0 ) 
{ }

Student_Info::Student_Info( const Student_Info& s )
{
	m_name = s.m_name;
	m_midterm = s.m_midterm;
	m_final = s.m_final;
	
	m_homework = s.m_homework;
}

Student_Info::Student_Info( ostream& out, istream& in )
{
	load( out, in );
}

Student_Info::~Student_Info() { }

#pragma endregion

#pragma region Public Interface

istream& Student_Info::load( ostream& out, istream& in )
{
	out << endl;
	
	out << "Name:";
	in.ignore();
	in >> m_name;

	out << "Midterm:";
	in.ignore();
	in >> m_midterm;

	out << "Final:";
	in.ignore();
	in >> m_final;

	::read_hw( out, in, m_homework );

	return in;
}

double Student_Info::grade() const
{
	return ::grade( m_midterm, m_final, m_homework );
}

#pragma endregion

#pragma region Internal

#pragma endregion