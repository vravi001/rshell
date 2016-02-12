//this is our main file
// testing
#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
using namespace std;
int main()
{
	vector<string> parse;
	string str;
	cout << "$";
	getline(cin, str);
	cout << endl;
	while(str != "exit")
	{
		typedef boost::toknizer<boost::char_separator<char> > Tok;
		boost::char_separator<shar> sep("", "|&#;");
		Tok tok(str, sep);
		for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
		{
			parse.push_back(*tok_iter);
		}
		//do class work here
		parse.clear();
		cout << "$";
		getline(cin, str);
		cout << endl;
	}

	return 0;
}

