#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_Collection;
typedef map<string, Rule_Collection> Grammar;

class Ch7
{
public:
	Ch7();
	~Ch7();

	void countWords();
	static vector<string> split( const string& input );
	map<string, vector<int> > xref( istream& in, vector<string> find_words( const string& ) );
	void gen_aux( const Grammar& g, const string& word, vector<string>& ret );
	vector<string> gen_sentence( const Grammar& g );
	bool bracketed( const string& s );
	Grammar read_grammar( istream& in );
	int nrand( int n );
};