Script started on Fri 04 Mar 2016 08:17:19 PM PST
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[?1034h[ybern004@hammer src]$ make
g++ -Wall -Werror -ansi -pedantic rshell.cpp -o rshell.out
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ makeexit./rshell.out
ybern004@hammer.cs.ucr.edu$ exit

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out
ybern004@hammer.cs.ucr.edu$ [ -e /class/classes/ybern004/CS-100/assign3/rshell/src ] exit

(True)
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out[8Pmake./rshell.out
ybern004@hammer.cs.ucr.edu$ echo a||exit

a
ybern004@hammer.cs.ucr.edu$ (echoa  a&&ech  o b)exit

a
b
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out
ybern004@hammer.cs.ucr.edu$ exit exit

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out
ybern004@hammer.cs.ucr.edu$ echo exit;exit

exit
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out
ybern004@hammer.cs.ucr.edu$ #exit

ybern004@hammer.cs.ucr.edu$ (echo a||exit)&&exit

a
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out[8Pmake./rshell.out
ybern004@hammer.cs.ucr.edu$ ls&&echo a||ls;exit

a.out		      exit.sh	makefile	    rshell.cpp	tests
commented_command.sh  main.cpp	precedence_test.sh  rshell.out	test_test.sh
a
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out[8Pmakeexitmake./rshell.out
ybern004@hammer.cs.ucr.edu$ (exit)

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out[8Pmake./rshell.out
ybern004@hammer.cs.ucr.edu$ exit&&exho a      choa    echo a

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out[8Pmake./rshell.out
ybern004@hammer.cs.ucr.edu$ ls -l&&ls&&[ -e /class/classes/ybern004/CS-100/assign3/rshell/src ]&&mkdir hi&&ls&&ls -a;exit

total 172
-rwxr-xr-x 1 ybern004 classes 66673 Mar  4 19:34 a.out
-rw-r--r-- 1 ybern004 classes  1627 Mar  4 20:17 commented_command.sh
-rw-r--r-- 1 ybern004 classes     0 Mar  4 20:17 exit.sh
-rw-r--r-- 1 ybern004 classes  2770 Mar  4 16:33 main.cpp
-rw-r--r-- 1 ybern004 classes   579 Mar  4 19:54 makefile
-rw-r--r-- 1 ybern004 classes  1739 Mar  4 20:13 precedence_test.sh
-rw-r--r-- 1 ybern004 classes  9979 Mar  4 19:34 rshell.cpp
-rwxr-xr-x 1 ybern004 classes 66673 Mar  4 20:17 rshell.out
drwxr-xr-x 2 ybern004 classes  4096 Mar  4 19:59 tests
-rw-r--r-- 1 ybern004 classes  2580 Mar  4 20:05 test_test.sh
a.out		      exit.sh	makefile	    rshell.cpp	tests
commented_command.sh  main.cpp	precedence_test.sh  rshell.out	test_test.sh
[: missing `]'
a.out		      exit.sh  main.cpp  precedence_test.sh  rshell.out  test_test.sh
commented_command.sh  hi       makefile  rshell.cpp	     tests
.   a.out		  exit.sh  main.cpp  precedence_test.sh  rshell.out  test_test.sh
..  commented_command.sh  hi	   makefile  rshell.cpp		 tests
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ [[K./rshell.out
ybern004@hammer.cs.ucr.edu$ [ -e /class/classes/ybern004/CS-100/assign3/rshell/src ]

(True)
ybern004@hammer.cs.ucr.edu$ exit

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ exit
exit

Script done on Fri 04 Mar 2016 08:24:08 PM PST
