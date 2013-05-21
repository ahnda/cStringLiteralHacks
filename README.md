cStringLiteralHacks
===================

A variety of hacks getting around a secret literal check in C. For funsies!

Read/Run
--------
Will read offset for literal found in hex editor,
then parrot it back to get past the strcmp.

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

###Pros:
+ No issues with regex choking on unexpected input
+ No problems maintaining a large enough buffer

###Cons:
- Potentially hazardous, could overwrite important information
- Modifies the executable
- Requires write permissions


