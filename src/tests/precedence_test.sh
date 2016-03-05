Script started on Fri 04 Mar 2016 08:06:32 PM PST
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[?1034h[ybern004@hammer src]$ make
g++ -Wall -Werror -ansi -pedantic rshell.cpp -o rshell.out
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ ./rshell.cpp[K[K[Kout
ybern004@hammer.cs.ucr.edu$ (test -e /class/classes/ybern004/CS-100/assign3/rshell/src)||(test -e /class/classes/ybern004/CS-100/assign3/rshell/src)

(True)
ybern004@hammer.cs.ucr.edu$ (test -e /class/classes/ybern004/CS-100/assign3/rshell/src)&&(test -e /class/classes/ybern004/CS-100/assign3/rshell/src)

(True)
(True)
ybern004@hammer.cs.ucr.edu$ ((test -e /class/classes/ybern004/CS-100/assign3/rshell/src)&&(test -e /class/classes/ybern004/CS-100/assign3/rshell/src))||test -e /class/classes/ybern004/CS-100/assign3/rshell/src

(True)
(True)
ybern004@hammer.cs.ucr.edu$ ((echo a&&echo b)||echo c)&&echo d

a
b
d
ybern004@hammer.cs.ucr.edu$ ((echo a&&echo b)e ||echo c)||echo d

a
b
ybern004@hammer.cs.ucr.edu$ (((echoa   a    a&&echo b)||cho c     echo c)&&echo d)&&echo e

a
b
d
e
ybern004@hammer.cs.ucr.edu$ (((echo a&&echo b)&&echo c)&& e  echo d)||echo e

a
b
c
d
ybern004@hammer.cs.ucr.edu$ (ech a  o a)&&(echo b)

a
b
ybern004@hammer.cs.ucr.edu$ ((echo a)&&(echo b))

a
b
ybern004@hammer.cs.ucr.edu$ echo a&&(echo c b||echo c)

a
b
ybern004@hammer.cs.ucr.edu$ echo a&&ec  (echo b&&(echo c))

a
b
c
ybern004@hammer.cs.ucr.edu$ echo a&&(echo b&&(echo c||echo d)&&echo e)

a
b
c
e
ybern004@hammer.cs.ucr.edu$ exit

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ exit
exit

Script done on Fri 04 Mar 2016 08:13:24 PM PST
