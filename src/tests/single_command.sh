Script started on Fri 12 Feb 2016 06:18:30 PM PST
]0;ybern004@hammer:~/CS-100/assign2/rshell/src[?1034h[ybern004@hammer src]$ g++ main.cpp
]0;ybern004@hammer:~/CS-100/assign2/rshell/src[ybern004@hammer src]$ ./a.out
ybern004@hammer.cs.ucr.edu$ ls -a

.  ..  a.out  .git  main.cpp  single_command.sh   test	txt.txt  win
ybern004@hammer.cs.ucr.edu$ ls -a l

total 68
-rwxr-xr-x 1 ybern004 classes 56134 Feb 12 18:18 a.out
-rw-r--r-- 1 ybern004 classes  2770 Feb 12 16:44 main.cpp
-rw-r--r-- 1 ybern004 classes     0 Feb 12 18:18 single_command.sh
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 15:37  test
-rw-r--r-- 1 ybern004 classes     0 Feb 12 18:16 txt.txt
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 16:04 win
ybern004@hammer.cs.ucr.edu$ echo hi

hi
ybern004@hammer.cs.ucr.edu$ git status

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
#	single_command.sh
#	txt.txt
no changes added to commit (use "git add" and/or "git commit -a")
ybern004@hammer.cs.ucr.edu$ mkdir sctest

ybern004@hammer.cs.ucr.edu$ ls -a

.  ..  a.out  .git  main.cpp  sctest  single_command.sh   test	txt.txt  win
ybern004@hammer.cs.ucr.edu$ ls

terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::substr
Aborted
]0;ybern004@hammer:~/CS-100/assign2/rshell/src[ybern004@hammer src]$ ./a.outg++ main.cpp[5P./a.out
ybern004@hammer.cs.ucr.edu$ echo Hello

Hello
ybern004@hammer.cs.ucr.edu$ ls -a

.  ..  a.out  .git  main.cpp  sctest  single_command.sh   test	txt.txt  win
ybern004@hammer.cs.ucr.edu$ ls -l

total 72
-rwxr-xr-x 1 ybern004 classes 56134 Feb 12 18:18 a.out
-rw-r--r-- 1 ybern004 classes  2770 Feb 12 16:44 main.cpp
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 18:19 sctest
-rw-r--r-- 1 ybern004 classes     0 Feb 12 18:18 single_command.sh
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 15:37  test
-rw-r--r-- 1 ybern004 classes     0 Feb 12 18:16 txt.txt
drwxr-xr-x 2 ybern004 classes  4096 Feb 12 16:04 win
ybern004@hammer.cs.ucr.edu$ echo world

world
ybern004@hammer.cs.ucr.edu$ git status

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
#	single_command.sh
#	txt.txt
no changes added to commit (use "git add" and/or "git commit -a")
ybern004@hammer.cs.ucr.edu$ mkdir thisdir

ybern004@hammer.cs.ucr.edu$ ls -a

.  ..  a.out  .git  main.cpp  sctest  single_command.sh   test	thisdir  txt.txt  win
ybern004@hammer.cs.ucr.edu$ touch testing.txt

ybern004@hammer.cs.ucr.edu$ ls -a

.  ..  a.out  .git  main.cpp  sctest  single_command.sh   test	testing.txt  thisdir  txt.txt  win
ybern004@hammer.cs.ucr.edu$ ls

terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::substr
Aborted
]0;ybern004@hammer:~/CS-100/assign2/rshell/src[ybern004@hammer src]$ exit
exit

Script done on Fri 12 Feb 2016 06:20:45 PM PST
