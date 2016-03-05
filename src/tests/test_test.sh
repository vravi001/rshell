Script started on Fri 04 Mar 2016 08:30:13 PM PST
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[?1034h[ybern004@hammer src]$ make
g++ -Wall -Werror -ansi -pedantic rshell.cpp -o rshell.out
]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ makeexit./rshell.out
ybern004@hammer.cs.ucr.edu$ test -e      /class/classes/ybern004/CS-100/assign3/rshell/src

(True)
ybern004@hammer.cs.ucr.edu$ test - e  e /class/classes/ybern004/CS-100/assign3/rshell/src

(True)
ybern004@hammer.cs.ucr.edu$ test -f /class/classes/ybern004/CS-100/assign3/rshell/src

(False)
ybern004@hammer.cs.ucr.edu$ test -d /class/classes/ybern004/CS-100/assign3/rshell/src

(True)
ybern004@hammer.cs.ucr.edu$ test    [ /class/classes/ybern004/CS-100/assign3/rshell/src ]

(True)
ybern004@hammer.cs.ucr.edu$ tes   [ -e /class/classes/ybern004/CS-100/assign3/rshell/src ]

(True)
ybern004@hammer.cs.ucr.edu$ [ -f /class/classes/ybern004/CS-100/assign3/rshell/src ]

(False)
ybern004@hammer.cs.ucr.edu$ [ -d /class/classes/ybern004/CS-100/assign3/rshell/src ]

(True)
ybern004@hammer.cs.ucr.edu$ test /class/classes/ybern004/CS-100/assign3/rshell/src/rshell.cpp

(True)
ybern004@hammer.cs.ucr.edu$ test -f   e /class/classes/ybern004/CS-100/assign3/rshell/src/rshe;;  ll.cpp

(True)
ybern004@hammer.cs.ucr.edu$ test -f /class/classes/ybern004/CS-100/assign3/rshell/src/rshell.cpp

(True)
ybern004@hammer.cs.ucr.edu$ test -d /class/classes/ybern004/CS-100/assign3/rshell/src/rshell.cpp

(False)
ybern004@hammer.cs.ucr.edu$ [ /class/classes/ybern004/CS-100/assign3/rshell/src/rshell.spp   cpp ]

(True)
ybern004@hammer.cs.ucr.edu$ [ -e /class/classes/ybern004/CS-100/assign3/rshell/src/rshe;;  ll.cpp ]

(True)
ybern004@hammer.cs.ucr.edu$ [ -f /class/classes/ybern004/CS-100/assign3/rshell/src/rshell.cpp ]

(True)
ybern004@hammer.cs.ucr.edu$ [ -d /class/classes/ybern004/CS-100/assign3/rshell/src/rshell.cpp ]

(False)
ybern004@hammer.cs.ucr.edu$ [ test /class/classes/ybern004/CS-100/assign3/rshell/src/filedoesntexist

(False)
ybern004@hammer.cs.ucr.edu$ test -e /class/classes/ybern004/CS-100/assign3/rshell/src/filedoesntexist

(False)
ybern004@hammer.cs.ucr.edu$ test -f /class/classes/ybern004/CS-100/assign3/rshell/src/filedoesntes xist

(False)
ybern004@hammer.cs.ucr.edu$ test -d /class/classes/ybern004/CS-100/assign3/rshell/src/filedoestn  ntexist

(False)
ybern004@hammer.cs.ucr.edu$ exit

]0;ybern004@hammer:~/CS-100/assign3/rshell/src[ybern004@hammer src]$ exit
exit

Script done on Fri 04 Mar 2016 08:34:10 PM PST
