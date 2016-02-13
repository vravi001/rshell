//this is our main file
// testing
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
using namespace std;


void execute(string command, bool &pass) {
	if(command == "exit")
	{
		exit(1);
	}
	int pos = command.find(" ");
	string c1 = command.substr(pos);
	string c0 = command.substr(0, pos); //see if +1 fixed out of range error
	//c0.erase(remove(c0.begin(), c0.end(), ' '), c0.end());
	c1.erase(remove(c1.begin(), c1.end(), ' '), c1.end());
	char *x = new char[c1.size() + 1];
	copy(c1.begin(), c1.end(), x);
	x[c1.size()] = '\0'; //took out this

	char *y = new char(c0.size() + 1);
	copy(c0.begin(), c0.end(), y);
	y[c0.size()] = '\0'; //took out this

	vector<char *> v;
	v.push_back(y);
	v.push_back(x); 

	char *cmd[] = {y, x, NULL};
	pid_t pid;
	int status;
	int cStatus;
	if((pid = fork())< 0)
	{
		cout << "Error: failed forking child process" << endl;
		exit(1);
	}
	else if(pid == 0)
	{
		status = execvp(y, cmd);
		if(status < 0)
		{
			pass = false;
		}
		else{
			pass = true;
		}
	}
	else{
		while(wait(&cStatus) !=pid)
		{
		}
	}
	delete[] x;
	delete[] y;
}

void connector(vector<string> parse)
{
	bool pass = true;
	int i = 0;
	string exec = parse.at(i);
	execute(exec, pass); //FIX THIS
	//cout << "Hello" << endl;
	//cout << "Parse vector size: " << parse.size() << endl;
	i = i+1;
	while(i < parse.size())
	{
		//cout << "Connector while loop" << endl;
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
			i = parse.size()+ 1;
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
		//cout << "In while loop" << endl;
		vector<string> parse;
		//vector<string> mod;
		typedef boost::tokenizer<boost::char_separator<char> > Tok;
		boost::char_separator<char> sep("", "|&#;"); //see if trailing newline is a problem
		Tok tok(str, sep);
		for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
		{
			parse.push_back(*tok_iter);
		}

		connector(parse);
		//do class work here
		//parse.clear();
		//cout << "In while loop 2" << endl;
		cout << getlogin() << "@" << hostname << "$ ";
		//cout << "$";
		getline(cin, str);
		cout << endl;
	}

	return 0;
}

