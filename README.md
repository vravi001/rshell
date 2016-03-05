#RSHELL

#Introduction:
The purpose of this assignment is to write a basic command shell. This shell will be able to print a command prompt, and read in a command on one line.

#Description of the Functions:
1. void testExecute(string command, bool &pass): 
This function is specifically for test commands. So, if the user enters such a 
command, the function takes in the parsed string as an argument and executes 
the command. It tests, using the -e, -f, -d flags, if the path provided is a 
valid file, directory or if it exists. We use the stat() function which returns 
an integer (): true, 1: false). This value is used to express if the item exists 
or not. Then, the output to the screen is (True) if item exists and (False) if not.
2. void execute(string command, bool &pass):
This function is used in order to execute every command except the test command. We 
are using the system call execvp(). So, an individual command is passed into the
function as an argument along with a boolean variable (passed by reference) and is
again parsed in order to comply with the function parameter requirements of execvp().
Then, the parsed string i pushed into an array of character pointers terminated by the
null pointer. This array is then passed into execvp(). We use fork(ing) in order to 
record the pas or fail result of execvp().
3. void connector(vector<string> parse, bool &pass, string &s):
This function takes in a vector of parsed strings, a boolean variable passed by 
reference. This function is responsible calling the testExecute() and execute() function
appropriately based on the pass/fail result of the functions. It also keeps track of the 
symbols (connectors) and then execute the next parsed string. It also saves the pass/fail
result of the testExecute and execute functions.
4. void tokenizer(string v, vector<string> &mod)
This function is used in order to parse strings. It parses the strings based on the 
delimiters (connectors) specified, and stores these new tokens in a vector of strings.
4. void par(vector<string> parse):
This function takes in a vector of strings. The vector of strings consists of the 
partially parsed user input strung. It then appropriately parses the strings at each
position in the vector using the above tokenizer function. After, it calls the connector()
function above, and keeps track of its progress.
5. int main():
This main function uses a sentinel controlled while loop such that if the user enters a 
string "exit", the program will terminate. The prompt will have the username and the hostname.
Then the user will enter a command string. Then, the command string will be partially parsed 
to that if the user enters any parantheses, the string will be separated accordingly. Then, the
par() function is called, and we pass in the parsed string. Then, the program will execute the 
command and repeat until the user either enters "exit" by itself or if "exit" is embedded 
in the command string.
#Description of Bugs
The following are a few bugs that were encountered while completing the project:
1. When running the program, after doing "git checkout hw2", you will need to run make within the src directory, using : "cd src" and then "make".
2. In the case that "bin/rshell" does not execute, type in ./rshell.out to run the executable.
3. When testing "exit" along with the test command with brackets, please enter it in this format:
	[ test command ]<space><exit>.
	-->There must be a space after the final bracket
4. Please follow *this* format for entering a command:
	[command][space][argument(s)][connector][command][space][argument(s)][connector]...
	--> Do not include a space before or after the connector.

