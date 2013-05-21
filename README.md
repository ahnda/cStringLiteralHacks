cStringLiteralHacks
===================

A variety of hacks getting around a secret literal check in C. For funsies!

Read/Run
--------
Will read offset for literal found in hex editor,
then parrot it back to get past the strcmp.

###Execution:

    gcc -o chal1 chal1.c
    gcc -o readRun chal1ReadRun.c
    ./readRun

###To Break:

    chmod 711 chal1

###Pros:
+ Leaves the executable intact
+ Doesn't require write permissions

###Cons:
- Is only as good as my regex (not good)
- Is useless if the secret is longer than my buffer
- Requires read permissions on file

Rewrite
-------
Will overwrite the memory starting at the offset
found in hex editor, then simply run the program
with the new value.

###Execution:

    gcc -o chal1 chal1.c
    gcc -o rewrite chal1Rewrite.c
    #Running this will modify the chal1 executable!
    ./rewrite

###To Break:

    chmod 711 chal1

###Pros:
+ No issues with regex choking on unexpected input
+ No problems maintaining a large enough buffer

###Cons:
- Potentially hazardous, could overwrite important information
- Modifies the executable
- Requires write permissions

LD_PRELOAD
----------
Places a custom implementation of strcmp in between chal1
and system libraries, allowing me to always evaluate to true.

###Execution:

    gcc -o chal1 chal1.c
    gcc -fPIC -DPIC -c strcmp.c
    #I don't think ld works on OSX. Hooray Linux!
    ld -shared -o strcmp.so strcmp.o -ldl
    LD_PRELOAD=./strcmp.so ./chal1 bingo

###To Break:

    chmod u+s chal1

###Pros:
+ No worrying about file offsets (less fragile)
+ Program is completely unaware of changes
+ No need to modify program code

###Cons:
- Well, maybe there's a strcmp in there I want!
- Must have proper permissions (can be disabled with +s)

