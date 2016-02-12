//this is our main file
// testing
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
using namespace std;

void execute(string command, bool &pass) {
	int pos = command.find(" ");
	string c1 = command.substr(pos);
	string c0 = command.substr(0, pos);

	vector<char *> v;
	v.push_back(c0);
	v.push_back(c1);

	char **cmd = &v[0];
	int status = execvp( v[0], cmd);
	if (status == -1 ) {
		pass = false;
	}
	else {
		pass = true;
	}
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

