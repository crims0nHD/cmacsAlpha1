How to write a module
----------------------
NOTE: this is a template module and only logs a message

1. implement include/module.h
2. check that ALL resources that are allocated by the module get cleaned up
   a. on exit
   b. on signal
3. Write Documentation
   a. moduleinfo.md - a file containing info on the purpouse of the module and the file structure
   b. comment/document API calls
4. Declare all functions that are only used within a file as static
