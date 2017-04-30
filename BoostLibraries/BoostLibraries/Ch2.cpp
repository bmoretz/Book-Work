#include "stdafx.h"
#include "Ch2.h"

Ch2::Ch2()
{
}


Ch2::~Ch2()
{
}

artiste_album_map latest_albums;

template<typename C>
boost::optional<typename C::mapped_type> lookup( const C& dict, const typename C::key_type key )
{
	typename C::const_iterator it = dict.find( key );

	return it != dict.end() ?
		it->second : boost::optional<C::mapped_type>();
}

void Ch2::FindArtists()
{
	latest_albums[ "Korn" ] = "";
	latest_albums[ "The Clash" ] = "London Calling";
	latest_albums[ "David Gilmour" ] = "On An Island";

	std::string artists[ 3 ]{ "Korn", "The Clash", "David Gilmour" };

	for ( const auto& artist : artists )
	{
		boost::optional<std::string> album
			= lookup( latest_albums, artist );

		if ( album )
		{
			std::cout << "The latest album from " << artist;

			if ( album->empty( ) )
			{
				std::cout << " is untitled" << std::endl;
			}
			else
			{
				std::cout << " is named " << *album << std::endl;
			}
		}
		else
		{
			std::cout << "No information on ablums from "
				<< artist << std::endl;
		}
	}
}

boost::optional<std::string> Ch2::find_latest_album_of( const std::string& artist_name )
{
	auto iter = latest_albums.find( artist_name );

	if ( iter != latest_albums.end() )
	{
		return iter->second;
	}
	else
	{
		return boost::none;
	}
}

std::tuple<size_t, size_t, double>
	Ch2::getBestTransactDays(std::vector<double> prices)
{
	double min = std::numeric_limits<double>::max();
	double gain = 0.0, max_gain = 0.0;

	size_t min_day, max_day;
	size_t buy_day;

	for( size_t i = 0, days = prices.size(); i < days; i++)
	{
		if (prices[i] < min) {
			min = prices[i];
			min_day = i;
		}
		else if( ( gain = prices[i] - min ) > max_gain) {
			max_gain = gain;
			buy_day = min_day;
			max_day = i;
		}
	}

	return std::make_tuple( buy_day, max_day, max_gain );
}

std::tuple<int, std::string> Ch2::get_tuple()
{
	return std::make_tuple( 1, std::string("test") );
}