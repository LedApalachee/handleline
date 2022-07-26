#ifndef handleline_h
#define handleline_h

#define BREAK_HANDLELINE 1

void handleline(int x1, int y1, int x2, int y2, int (*handle_tile)(int, int));

#endif


/*

handle_tile function is a function that is called at every step of a building line. Its purpose is to handle the current tile:
e.g. draw a character at its coordinates or any other action

the function must be of the following kind:
int handle_tile(int x, int y)

if the returning number of thsi function is 1, then it indicates the handleline function to break (or you can use the macro above);

*/