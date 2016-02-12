//this is our main file
// testing
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
using namespace std;

void connector(vector<string> parse)
{
	bool pass = true;
	int i = 1;
	string exec = parse.at(0);
	execute(exec, pass);
	while(i < parse.size())
	{
		if(parse.at(i) == "&")
		{
			if(pass)
			{
				exec = parse.at(i+2);
				execute(exec, pass);
			}
			i = i + 3;
		}
		else if(parse.at(i) == "|")
		{
			if(!pass)
			{	exec = parse.at(i+2);
				execute(exec, pass);
			}
			i = i + 3;
		}
		else if(parse.at(i) == ";")
		{
			exec = parse.at(i+1);
			execute(exec, pass);
			i = i + 2;
		}
	}
	return;
}
		
int main()
{
	char hostname[150];
	gethostname(hostname, sizeof hostname);

	vector<string> parse;
	string str;
	cout << getlogin() << "@" << hostname << "$ ";
	//cout << "$";
	getline(cin, str);
	cout << endl;
	while(str != "exit")
	{
		typedef boost::tokenizer<boost::char_separator<char> > Tok;
		boost::char_separator<char> sep("", "|&#;");
		Tok tok(str, sep);
		for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
		{
			parse.push_back(*tok_iter);
		}
		//do class work here
		parse.clear();
		cout << getlogin() << "@" << hostname << "$ ";
		//cout << "$";
		getline(cin, str);
		cout << endl;
	}

	return 0;
}

