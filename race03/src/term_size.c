#include "../inc/header.h"

void term_size(WINDOW *mainwin,int *row, int *col) {
	getmaxyx(mainwin, *row, *col);
}

