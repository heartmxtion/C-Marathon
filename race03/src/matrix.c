#include "../inc/header.h"

int matrix(WINDOW *mainwin) {
	int speed = 50;
	int row_size, col_size;//, r, c;
	term_size(mainwin, &col_size, &row_size);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	//halfdelay(1);
	curs_set(false);
	noecho();
	struct colms *matrix = (struct colms*)malloc(sizeof(struct colms) * row_size);
	for(int i = 0; i < row_size; i++) {
		matrix[i].arr = (wchar_t*)malloc(sizeof(wchar_t) * col_size);
		for (int j = 0; j < col_size; j++) {
			matrix[i].arr[j] = get_rain_symbols();
		}
		matrix[i].length = rand() % col_size;
		matrix[i].start = 0 - matrix[i].length - matrix[i].length;
		matrix[i].finish = 0 - matrix[i].length;
	}
	wbkgd(mainwin, COLOR_PAIR(2));
	wclear(mainwin);
	print_massege(mainwin, col_size, row_size);
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			matrix[i].arr[j] = get_rain_symbols();
		}
	}
	while(true) {
		wtimeout(mainwin, speed);
		switch(getch()) {
		case 'w': if (speed > 10) speed -= 10; break;
		case 's': if (speed < 150) speed += 10; break;
		}
		if (getch() == 'q') {
			break;
		}
		wclear(mainwin);
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (j >= matrix[i].start && j <= matrix[i].finish ) {
					
					if (j == matrix[i].finish) {
						attroff(COLOR_PAIR(2));
						attron(COLOR_PAIR(1));
					}
					//mvwaddch(mainwin, j, i * 2, matrix[i].arr[j]);
					mvprintw(j, i * 2, "%lc", matrix[i].arr[j]);
					if (j == matrix[i].finish) {
						attroff(COLOR_PAIR(1));
						attron(COLOR_PAIR(2));
					}
					if (j == matrix[i].start) {
						matrix[i].arr[j] = get_rain_symbols();
					}
					if (j == matrix[i].finish) {
						matrix[i].arr[j] = get_rain_symbols();
					}
				}
			}
			matrix[i].start++;
			matrix[i].finish++;
			if (matrix[i].start > col_size) {
				matrix[i].length = rand() % col_size;
				matrix[i].start = 0 - matrix[i].length - matrix[i].length;
				matrix[i].finish = 0 - matrix[i].length;
			}	
		}
		refresh();
		//usleep(speed);
	}
	for(int i = 0; i < col_size; i++) {
		free(matrix[i].arr);
	}
	free(matrix);
	matrix = NULL;
	return 0;
}

