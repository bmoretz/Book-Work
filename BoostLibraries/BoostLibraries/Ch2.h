#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <boost/optional.hpp>
#include <boost/tuple/tuple.hpp>

typedef std::map<std::string, std::string> artiste_album_map;

extern artiste_album_map latest_albums;

class Ch2
{
public:
	Ch2();
	~Ch2();

	void FindArtists();

	boost::optional<std::string> find_latest_album_of( const std::string& artist_name );

	std::tuple<size_t, size_t, double> getBestTransactDays( std::vector<double> );

	std::tuple<int,std::string> get_tuple();
};