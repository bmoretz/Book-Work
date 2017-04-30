#include "stdafx.h"
#include "Ch2.h"


Ch2::Ch2()
{}


Ch2::~Ch2()
{}

void Ch2::Greeting()
{
	std::cout << "Please enter your name: ";
	
	std::string name;
	std::cin >> name;

	std::cout << name;

	const int total_rows = ( padding_rows * 2 ) + 3;
	const int total_columns = ( padding_characters * 2 ) + name.length() + 2;

	std::cout << std::endl << std::endl;

	const std::string greeting = '*' + std::string( padding_characters, ' ' ) + name + std::string( padding_characters, ' ' ) + '*';
	const std::string padding = '*' + std::string( total_columns - 2, ' ' ) + '*';

	for( int current_row = 0; current_row < total_rows; current_row++ )
	{
		if( current_row == 0 || current_row == total_rows - 1 )
		{
			std::cout << std::string( total_columns, '*' );
		}
		else if( current_row != ( int ) total_rows / 2 )
		{
			std::cout << padding;
		}
		else
		{ 
			std::cout << greeting;
		}

		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
}

void Ch2::Excersize1()
{
	std::cout << "Please enter your name: ";

	std::string name;
	std::cin >> name;

	std::cout << name;

	const std::string greeting = "Hello, " + name + "!";

	const int total_rows = ( padding_rows * 2 ) + 3;

	const std::string::size_type total_columns = greeting.size() + ( padding_characters * 2 ) + 2;
	
	std::cout << std::endl;

	for( int current_row = 0; current_row != total_rows; current_row++ )
	{
		int current_column = 0;

		while( current_column < total_columns )
		{ 
			if( 
				( current_row == 0 || current_row == total_rows - 1 ) 
				|| 
				( current_column == 0 || current_column == total_columns - 1 ) 
			  )
			{
				std::cout << "*";
			}
			else if( current_row == padding_rows + 1 && current_column == padding_characters + 1 )
			{
				std::cout << greeting;
				current_column += greeting.size() - 1;
			}
			else
			{
				std::cout << " ";
			}

			current_column++;
		}
		
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
}