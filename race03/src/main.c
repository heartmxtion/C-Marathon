#include "../inc/header.h"

int main() {
	setlocale(LC_ALL, "ja_JP.UTF-8");
	WINDOW * mainwin;
	mainwin = initscr();
	curs_set(0);
	matrix(mainwin);
	delwin(mainwin);
	endwin();
	return 0;
}

