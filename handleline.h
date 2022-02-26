#ifndef handleline_h
#define handleline_h

#define BREAK_HANDLING_LINE 1

void handleline(int x1, int y1, int x2, int y2, long long int (*handle_tile)(int, int));

#endif


/*

handle_tile function is a function that is called at every step of a building line. Its purpose is to handle the current tile:
e.g. draw a character at its coordinates or do any other action

the function must be the following kind:
long long int handle_tile(int x, int y)

the returning type is long long because of its universal purpose: wheter it must be some special value or a pointer
if the returning number is 1, then it indicates the handleline function to break (or you can use the macro above);

*/