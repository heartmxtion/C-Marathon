#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c);
void mx_print_first_plus(int j, int n) {
	if (j == n * 2 + n / 2 + 3 - 1 || j == n / 2 + 1) {
		mx_printchar('+');
	} else if (j > n / 2 + 1 && j < n * 2 + n / 2 + 3) {
		mx_printchar('-');
	} else {
		mx_printchar(' ');
	}
}
void mx_fill_cube(int j, int n) {
	if (j > 0 && j < n * 2 + n / 2 + 3 - (n / 2 + 2)) {
		mx_printchar('-');
	} else {
		mx_printchar(' ');
	}
}
void mx_print_second_plus(int j, int n, int i) {
	if (j == 0 || j == n * 2 + n / 2 + 3 - (n / 2 + 2)) {
		mx_printchar('+');
	} else if (j == n * 2 + n / 2 + 2 && i < n + 2) {
		mx_printchar('|');
	} else {
		mx_fill_cube(j, n);
	}
}
void mx_print_borders(int j, int i, int n, int counter) {
	if (j == 0 || j == n * 2 + n / 2 + 3 - (n / 2 + 2)) {
		mx_printchar('|');
	} else if (j == n * 2 + n / 2 + 2
			&& i < n + n / 2 + 1 - n / 2) {
		mx_printchar('|');
	} else if (j == n * 2 + n / 2 + 3 - counter - 2
			&& i > n + n / 2 + 1 - n / 2) {
		mx_printchar('/');
	} else if (j == n * 2 + n / 2 + 2
			&& i >= n + n / 2 + 1 - n / 2
			&& i < n + n / 2 + 1 - n / 2 + 1) {
		mx_printchar('+');
	} else {
		mx_printchar(' ');
	}
}
void mx_print_slash_borders(int j, int counter, int n) {
	if (j == (n / 2 + 1) - counter || j == n * 2 + n / 2 + 3 - counter - 1) {
		mx_printchar('/');
	} else if (j == n * 2 + n / 2 + 2) {
		mx_printchar('|');
	} else {
		mx_printchar(' ');
	}
}

void mx_cube(int n) {
	int counter = 0;
	if(n<2){
		return;
	}
	for (int i = 0; i < n + n / 2 + 3; i++) {
		for (int j = 0; j < n * 2 + n / 2 + 3; j++) {
			if (i == 0) {
				mx_print_first_plus(j, n);
			} else if (i == n / 2 + 1 || i == n + n / 2 + 3 - 1) {
				mx_print_second_plus(j, n, i);
			} else if (i >= n / 2 + 2 && i != n + n / 2 + 3 - 1) {
				mx_print_borders(j, i, n, counter);
			} else if (i <= n / 2) {
				mx_print_slash_borders(j, counter, n);
			} else {
				mx_printchar(' ');
			}
		}
		counter = counter + 1;
		if (i == n + n / 2 + 3 - n / 2 - 2) {
			counter = 0;
		}
		mx_printchar('\n');
	}
}

