#RSHELL

#Introduction:
The purpose of this assignment is to write a basic command shell. This shell will be able to print a command prompt, and read in a command on one line.

#Description of the Functions:
1. void execute(string command, bool pass): This function will be executing commands one by one by using the system call execvp(). This will be using child and parent processes in order to capture the progress of execvp().
2. void connector(vector<string> parse): This function will be taking in the parsed command string and will be making function calls to void execute(string command, bool pass) by iterating through the parse vector. This function will also be keeping track of the progress of the void execute(string command, bool pass) function, and will be deciding whether the next command will be executed or not.
3. int main(): the main function will be taking in the user entered command and will be parsing the command accordingly. This function will be making calls to void connector(vector<string> parse) until the user exits the shell.

#Description of Bugs
The following are a few bugs that were encountered while completing the project:
1. When running the program, after doing "git checkout hw1", you will need to run make within the src directory, using : "cd src" and then "make".
2. The shell does not work for the command "ls", it will throw an out of range error and terminate; however, it works for "ls" with flags.
3. The shell sometimes exits when the user enters explicitely "exit" twice; however "exit" does work well when it is included along with other commands.
4. Please follow *this* format for entering a command:
	[command][space][argument(s)][connector][command][space][argument(s)][connector]...
	--> Do not include a space before or after the connector.

