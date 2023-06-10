#include "../inc/header.h"

void print_massege(WINDOW *mainwin, int col, int row) {
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wbkgd(mainwin, COLOR_PAIR(3));
	if (row > 30 && col > 20) {
		int i = col / 16;
		int j = row / 16;
		usleep(15000);
		char string1[] = "Wake up , Neo..";
		char string2[] = "The Matrix has you..";
		char string3[] = "Follow the white rabbit";
		char string4[] = "Knock, knock, Neo";
		wclear(mainwin);
		int k = 0;
		while (k < 15) {
			mvwaddch(mainwin, j, i + k, string1[k]);
			refresh();
			usleep(170000);
			k++;
		}
		k = 0;
		wclear(mainwin);
		usleep(100000);
		while (k < 20) {
			mvwaddch(mainwin, j, i + k, string2[k]);
			refresh();
			usleep(170000);
			k++;
		}
		k = 0;
		wclear(mainwin);
		usleep(100000);
		while (k < 23) {
			mvwaddch(mainwin, j, i + k, string3[k]);
			refresh();
			usleep(170000);
			k++;
		}
		k = 0;
		wclear(mainwin);
		usleep(100000);
		while (k < 17) {
			mvwaddch(mainwin, j, i + k, string4[k]);
			refresh();
			usleep(170000);
			k++;
		}
		k = 0;
	}
}

