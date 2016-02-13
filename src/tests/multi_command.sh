Script started on Fri 12 Feb 2016 06:25:07 PM PST
]0;ybern004@hammer:~/CS-100/assign2/rshell/src[?1034h[ybern004@hammer src]$ exit[Kg++ main.cpp
]0;ybern004@hammer:~/CS-100/assign2/rshell/src[ybern004@hammer src]$ ./a.out
ybern004@hammer.cs.ucr.edu$ ls -a;echo hello;  echo world

.  ..  a.out  .git  main.cpp  multi_command.sh	sctest	single_command.sh   test  testt  thisdir  win
hello
world
ybern004@hammer.cs.ucr.edu$ ls -l;mkdir testtt&&ls -a

total 84
-rwxr-xr-x 1 ybern004 classes 56134 Feb 12 18:25 a.out
-rw-r--r-- 1 ybern004 classes  2770 Feb 12 16:44 main.cpp
-rw-r--r-- 1 ybern004 classes     0 Feb 12 18:25 multi_command.sh
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:19 sctest
-rw-r--r-- 1 ybern004 classes  3417 Feb 12 18:20 single_command.sh
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 15:37  test
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:22 testt
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:20 thisdir
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 16:04 win
.  ..  a.out  .git  main.cpp  multi_command.sh	sctest	single_command.sh   test  testt  testtt  thisdir  win
ybern004@hammer.cs.ucr.edu$ mkdir test1||echo hello&&echo world

world
ybern004@hammer.cs.ucr.edu$ ls -a&&ls-  -l;echo testing;git status

.  ..  a.out  .git  main.cpp  multi_command.sh	sctest	single_command.sh   test  test1  testt	testtt	thisdir  win
total 92
-rwxr-xr-x 1 ybern004 classes 56134 Feb 12 18:25 a.out
-rw-r--r-- 1 ybern004 classes  2770 Feb 12 16:44 main.cpp
-rw-r--r-- 1 ybern004 classes     0 Feb 12 18:25 multi_command.sh
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:19 sctest
-rw-r--r-- 1 ybern004 classes  3417 Feb 12 18:20 single_command.sh
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 15:37  test
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:27 test1
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:22 testt
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:26 testtt
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:20 thisdir
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 16:04 win
testing
# On branch master
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   main.cpp
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	a.out
#	multi_command.sh
#	single_command.sh
no changes added to commit (use "git add" and/or "git commit -a")
ybern004@hammer.cs.ucr.edu$ echo hello&&echo im&&echo testing&&echo my||echo program

hello
im
testing
my
ybern004@hammer.cs.ucr.edu$ mkdir test2||echo hello||echo word ld||git status

ybern004@hammer.cs.ucr.edu$ ls -a;echo hello&&mkdir test3||ex cho world;git sst  tatus

.  ..  a.out  .git  main.cpp  multi_command.sh	sctest	single_command.sh   test  test1  test2	testt  testtt  thisdir	win
hello
# On branch master
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   main.cpp
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	a.out
#	multi_command.sh
#	single_command.sh
no changes added to commit (use "git add" and/or "git commit -a")
ybern004@hammer.cs.ucr.edu$ echo hello;echo my;echo name;echo is;echo bob

hello
my
name
is
bob
ybern004@hammer.cs.ucr.edu$ git status||ls -a

# On branch master
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   main.cpp
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	a.out
#	multi_command.sh
#	single_command.sh
no changes added to commit (use "git add" and/or "git commit -a")
ybern004@hammer.cs.ucr.edu$ touch see.txt&&touch if.txt&&touch this.txt&&  ||touch appears.txt||touch shows.txt

ybern004@hammer.cs.ucr.edu$ ls -a

.  ..  a.out  .git  if.txt  main.cpp  multi_command.sh	sctest	see.txt  single_command.sh   test  test1  test2  test3	testt  testtt  thisdir	this.txt  win
ybern004@hammer.cs.ucr.edu$ exit

]0;ybern004@hammer:~/CS-100/assign2/rshell/src[ybern004@hammer src]$ exit
exit

Script done on Fri 12 Feb 2016 06:32:17 PM PST
