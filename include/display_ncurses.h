#ifndef __DISPLAY_NCURSES_H_
#define __DISPLAY_NCURSES_H_

// Start ncuses and setup ncurses stuff
extern int display_ncurses_start();

// Stop ncurses and free ncurses stuff
extern int display_ncurses_stop();

// Loop routine for input
// Returns -1 for error
// Returns 0 for normal input
// Returns 1 for CTRL C
extern int display_ncurses_routine_input();

// Loop routine for output
extern int display_ncurses_routine_output();

#endif // __DISPLAY_NCURSES_H_
