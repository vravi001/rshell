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

	//const char *x = c1.c_str();
	//const char *y = c0.c_str();
	
	char *x = new char[c1.size() + 1];
	copy(c1.begin(), c1.end(), x);
	x[c1.size()] = '\0';
	
	char *y = new char(c0.size() + 1);
	copy(c0.begin(), c0.end(), y);
	y[c0.size()] = '\0';


	vector<char *> v;
	//v.push_back(y); //
	v.push_back(y);
	v.push_back(x);
	//v.push_back(NULL);
	//char **cmd = &v[0];
	char *cmd[] = {y, x, NULL};
	int status = execvp(v[0], cmd);
	if (status == -1) {
		pass = false;

	}
	else {
		pass = true;
	}
	cout << "Status of " << command << " : " << status << endl;
	delete[] x;
	delete[] y;
}

void connector(vector<string> parse)
{
	bool pass = true;
	int i = 1;
	string exec = parse.at(0);
	execute(exec, pass);
	cout << "Hello" << endl;
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
		else if(parse.at(i) == "#")
		{
			i = parse.size();
		}
	}
	return;
}
		
int main()
{
	char hostname[150];
	gethostname(hostname, sizeof hostname);

	//vector<string> parse;
	string str;
	cout << getlogin() << "@" << hostname << "$ ";
	//cout << "$";
	getline(cin, str);
	cout << endl;
	while(str != "exit")
	{
		vector<string> parse;
		//vector<string> mod;
		typedef boost::tokenizer<boost::char_separator<char> > Tok;
		boost::char_separator<char> sep("", "|&#;");
		Tok tok(str, sep);
		for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
		{
			parse.push_back(*tok_iter);
		}
		//int min = 0;
		//int temp = 0;
		//for(int i = 0; i < parse.size(); ++i)
		//{
		//	if(parse.at(i) == "#")
		//	{
		//		temp = i;
		//	}
		//	if(temp < min)
		//	{
		//		min = temp;
		//	}
		//}

		connector(parse);
		//do class work here
		parse.clear();
		cout << getlogin() << "@" << hostname << "$ ";
		//cout << "$";
		getline(cin, str);
		cout << endl;
	}

	return 0;
}

