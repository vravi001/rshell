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
		x[path.size()] = '\0'
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
