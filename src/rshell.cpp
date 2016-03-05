#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <sys/stat.h>

using namespace std;

/*This function is specifically for test commands. So, if the user enters 
 * such a command, the function takes in the parsed string as an argument and
 * executes the command. It tests, using the -e -f and -d flags, if the path
 * provided is a valid file, directory or if it exists. We use the stat() 
 * fundtion which returns an integer (0: true, 1: false). This value is used 
 * to express if the item exists or not. Then, the output to the screen is 
 * (True) if item exists and (False) if not.*/ 

void testExecute(string command, bool &pass) {
	pass = false;
	bool check = false;
	if((command[command.size() - 1] == ']') && (command.size() > 2)) {
		command.erase(command.end() - 1);
		command.erase(command.end() - 1);
	}
	if((command.size() > 7) && (command[command.size() - 1] == 't') && (command[command.size() - 2] == 'i') && (command[command.size() - 3] == 'x') && (command[command.size() - 4] == 'e')) {
		check = true;
   		command.erase(command.end() - 1);
		command.erase(command.end() - 1);
		command.erase(command.end() - 1);
		command.erase(command.end() - 1);
		command.erase(command.end() - 1);
		command.erase(command.end() - 1);
		command.erase(command.end() - 1);
	}
	int pos = command.find(" ");
	string sub = command.substr(pos);

	sub.erase(sub.begin());

	if(sub[0] == '-') { //contains flag
		int pos2 = sub.find(" "); //finds the pos of the space after the flag
		string path = sub.substr(pos2);
		path.erase(path.begin()); // no space at the front	
		string flag = sub.substr(0, pos2); // no space at the end

		char *x = new char[path.size() + 1];
		copy(path.begin(), path.end(), x);
		x[path.size()] = '\0';
		struct stat s;
		if (flag == "-e") { //checking the -e flag
			if (stat(x, &s) == 0) {
				pass = true;
			}
			else {
				pass = false;
			}
		}
		else if( flag == "-f") { //checking the -f flag
			if(stat(x, &s) == 0) {
				if(S_ISREG(s.st_mode)) {
					pass = true;
				}
			}
		}
		else if(flag == "-d") { //checking the -d flag
			if(stat(x, &s) == 0) {
				if(S_ISDIR(s.st_mode)) {
					pass = true;
				}
			}
		}
	}

	else { //there's no flag, check if it exists
		char *x = new char[sub.size() + 1];
		copy(sub.begin(), sub.end(), x);
		x[sub.size()] = '\0';
		struct stat s;
		if(stat(x, &s) == 0) {
			pass = true;
		}
	}

	//outputting if true or false
	if(pass) {
		cout << "(True)" << endl;
	}
	else {
		cout << "(False)" << endl;
	}

	if(check) {
		exit(0);
	}
}

/*This function is used in order to execute every command except the 
 test command. We are using the system call execvp(). So, an individual 
 command is passed into the function as an argument along with a boolean 
 variable (passed by reference) and is again parsed in order to comply 
 with the function parameter requirements of execvp(). Then, the parsed 
 string is pushed into an array of character pointers terminated by the 
 null pointer. This array is then passed into execvp(). We use fork(ing) 
 in order to record the pass or fail result of execvp().*/

 void execute(string command, bool &pass) {
 	if(command == "exit") {
		exit(0);
	}
	if(command == "ls") {
		char *z = new char(command.size() + 1);
		copy(command.begin(), command.end(), z);
		z[command.size()] = '\0';

		vector<char *> v1;
		v1.push_back(z);

		char *cmd1[] = {z, NULL};

		pid_t pid1;
		int status1;
		int cStatus1;
		
		if((pid1 = fork()) < 0) {
			cout << "Error: failed forking child process" << endl;
			exit(1);
		}
		else if(pid1 == 0){
			status1 = execvp(z, cmd1);
			if(status1 < 0) {
				pass = false;
			}
			else {
				pass = true;
			}
		}
		else {
			while(wait(&cStatus1) != pid1) {}
		}
		delete[] z;
		return;
	}

	int pos = command.find(" ");
	string c1 = command.substr(pos);
	string c0 = command.substr(0, pos);
	c1.erase(remove(c1.begin(), c1.end(), ' '), c1.end());
	char *x = new char[c1.size() + 1];
	copy(c1.begin(), c1.end(), x);
	x[c1.size()] = '\0';

	char *y = new char(c0.size() + 1);
	copy(c0.begin(), c0.end(), y);
	y[c0.size()] = '\0';

	vector<char *> v;
	v.push_back(y);
	v.push_back(x);

	char *cmd[] = {y, x, NULL};
	pid_t pid;
	int status;
	int cStatus;
	if((pid = fork()) < 0) {
		cout << "Error; failed forking child process" << endl;
	}
	else if(pid == 0) {
		status = execvp(y, cmd);
		if(status < 0) {
			pass = false;
		}
		else {
			pass = true;
		}
	}
	else {
		while(wait(&cStatus) != pid) {}
	}
	delete[] x;
	delete[] y;
}

/*This function takes in a vector ofparsed strings, a boolean variable
 * passed by reference, and a string also passed by reference. This 
 * function is responsible for calling the testExecute() and execute() 
 * functions appropriately based on the pass/fail result of the functions. 
 * It also keeps track of the symbols (or connectors) in the case of the
 * parsed string having connectors in the end. It would use the saved 
 * symbols (connectors) and then execute the next parsed string. It also 
 * saves the pass/fail result of the testExecute and execute functions. */

void connector(vector<string> parse, bool &pass, string &s)
{
	string save = s;
	unsigned int i = 0; //changed to unsigned from int
	string exec = parse.at(i);

	while(i < parse.size())
	{
		if(parse.at(i).find("exit") == 0)
		{
			exit(0);
		}

		if((parse.at(i) == "&") || (save == "&"))
		{
			if((pass) && (save == "&"))
			{	
				exec = parse.at(i);
				execute(exec, pass);
				save = "";
			}
			else if((pass) && ((i + 2) < parse.size()))
			{
				exec = parse.at(i + 2);
				execute(exec, pass);
			}
			else if(((i + 2) >= parse.size()) && (save != ""))
			{
				save = "&";
			}
			i = i + 3;
		}
		else if((parse.at(i) == "|") || (save == "|"))
		{
			if((!pass) && (save == "|"))
			{
				exec = parse.at(i);
				execute(exec, pass);
				save = "";
			}
			else if((!pass) && ((i + 2) < parse.size()))
			{
				exec = parse.at(i + 2);
				execute(exec, pass);
			}
			else if((i + 2) >= parse.size())
			{
				save = "|";
			}
			i = i + 3;
		}
		else if((parse.at(i) == ";") || (save == ";"))
		{
			if(save == ";")
			{
				exec = parse.at(i);
				execute(exec, pass);
				save = "";
			}
			else if((i + 1) < parse.size())
			{
				exec = parse.at(i + 1);
				execute(exec, pass);
			}
			else
			{
				save = ";";
			}
			i = i + 2;
		}
		else if((parse.at(i) == "#") || (save == "#"))
		{
			if(save == "#")
			{
				i = parse.size() + 1;
				save = "";
			}
			else if((i + 1) < parse.size())
			{
				i = parse.size() + 1;
			}
			else
			{
				save = "#";
			}
			i = parse.size() + 1;
		}
		else if((save != "|") && (save != "&") && (save != ";") && (save != "#"))
		{
			if((parse.at(i).find("test") == 0) || (parse.at(i).find("[") == 0))
			{
				exec = parse.at(i);
				testExecute(exec, pass);
				i = i + 1;
			}
			else
			{
				exec = parse.at(i);
				execute(exec, pass);
				i = i + 1;
			}
		}
		else if((parse.at(i).find("test") == 0) || (parse.at(i).find("[") == 0))
		{
			exec = parse.at(i);
			testExecute(exec, pass);
			i = i + 1;
		}
	}
	s = save;
	return;
}

/*This function is used in order to parse strings. It parses 
 * the strings based on the delimiters specified, and stores 
 * these new tokens in a vector of strings. */
void tokenizer(string v, vector<string> &mod)
{
	mod.clear();
	typedef boost::tokenizer<boost::char_separator<char> > Tok;
	boost::char_separator<char> separ("", ";|&#");
	Tok token(v, separ);
	for(Tok::iterator iter = token.begin(); iter != token.end(); ++iter)
	{
		mod.push_back(*iter);
	}
	return;
}

/*This function takes in a vector of strings. The vector of strings
 * consists of the partially parsed user input string. It then appropriately
 * pases the strings at each position in the vector using the above
 * tokenizer function. After, it calls the connector() function above,
 * and keeps track of its progress. */

void par(vector<string> parse)
{
	string s;
	bool his = true;
	unsigned int i = 0;
	vector<string> mod;
	tokenizer(parse.at(i), mod);
	connector(mod, his, s);
	i = i + 1;
	while(i < parse.size())
	{
		if(parse.at(i) == ";")
		{
			i = i + 1;
			tokenizer(parse.at(i), mod);
			connector(mod, his, s);
			i = i + 1;
		}
		else if(parse.at(i) == "||")
		{
			i = i + 1;
			if(!his)
			{
				tokenizer(parse.at(i), mod);
				connector(mod, his, s);
			}
			i = i + 1;
		}
		else if(parse.at(i) == "&&")
		{
			i = i + 1;
			if(his)
			{
				tokenizer(parse.at(i), mod);
				connector(mod, his, s);
			}
			i = i + 1;
		}
		else if(parse.at(i) == "#")
		{
			i = parse.size() + 1;
		}
		else
		{
			tokenizer(parse.at(i), mod);
			connector(mod, his, s);
			i = i + 1;
		}
	}
}

/*This main function uses a sentinel controlled while loop
 * such that if the user enters a string "exit", the program
 * will terminate. The prompt will have the username and hostname. 
 * Then the user will enter a command string. Then, the command
 * string will be partially parsed so that if the user enters 
 * any parantheses, the string will be separated appropriatly.
 * Then, the par() function is called, and we pass in the parsed 
 * string. Then the program will execute the command and repeat until 
 * the user enters "exit" by itself or if "exit" is embedded in
 * the command string. */

int main()
{
	char hostname[150];
	gethostname(hostname, sizeof hostname);

	string str;
	cout << getlogin() << "@" << hostname << "$ ";
	getline(cin, str);
	cout << endl;
	while(str != "exit")
	{
		vector<string> parse;
		typedef boost::tokenizer<boost::char_separator<char> > Tok;
		boost::char_separator<char> sep("()", "");
		Tok tok(str, sep);
		for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
		{
			parse.push_back(*tok_iter);
		}
		par(parse);
		cout << getlogin() << "@" << hostname << "$ ";
		getline(cin, str);
		cout << endl;
	}

	return 0;
}








