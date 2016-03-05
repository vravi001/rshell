Script started on Fri 04 Mar 2016 08:13:51 PM PST
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[?1034h[ybern004@hammer src]$ make
g++ -Wall -Werror -ansi -pedantic rshell.cpp -o rshell.out
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ makeexit./rshell.out
ybern004@hammer.cs.ucr.edu$ #echo a&&echo a b

ybern004@hammer.cs.ucr.edu$ ls -a&&echo b#echo c

.   a.out		  main.cpp  precedence_test.sh	rshell.out  test_test.sh
..  commented_command.sh  makefile  rshell.cpp		tests
b
ybern004@hammer.cs.ucr.edu$ #[ -e /class/classes/ybern004/CS-100/assign3/rshell/src ]

ybern004@hammer.cs.ucr.edu$ [ -e /class/classes/ybern004/CS-100/assign3/rshell/src ]&&echo a#echo b

(True)
a
ybern004@hammer.cs.ucr.edu$ #exit

ybern004@hammer.cs.ucr.edu$ exit#echo a

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.out
ybern004@hammer.cs.ucr.edu$ echo a&&(echo b#echo c)

a
b
ybern004@hammer.cs.ucr.edu$ (#echo a)||echo b

ybern004@hammer.cs.ucr.edu$ ls -a  #[ -e /class/classes/ybern004/CS-100/assign3/rshell/src ]

.   a.out		  main.cpp  precedence_test.sh	rshell.out  test_test.sh
..  commented_command.sh  makefile  rshell.cpp		tests
ybern004@hammer.cs.ucr.edu$ [   (ech a   o   ho a&&echo b)#echo c

a
b
ybern004@hammer.cs.ucr.edu$ (#)

ybern004@hammer.cs.ucr.edu$ test - e  e /class/classes/ybern004/CS-100/assign3/rshell/src#echo a

(True)
ybern004@hammer.cs.ucr.edu$ exit

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ exit
exit

Script done on Fri 04 Mar 2016 08:17:09 PM PST
