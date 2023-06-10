#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c);

void mx_pyramid(int n) {
	if (n < 2 || 0 != n % 2) {
		return;
	}
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (j == n - i - 1) {
				mx_printchar('/');
			} else if (j == (n - i - 1) + counter) {
				mx_printchar('\\');
			} else if (i < n / 2
					&& j == n - i + counter + i) {
				mx_printchar('\\');
				break;
			} else if (i >= n / 2
					&& j == n * 2 - 1) {
				mx_printchar('|');
				break;
			} else if (i == n - 1
					&& j > n - i - 1
					&& j < (n - i - 1) + counter) {
				mx_printchar('_');
			} else {
				mx_printchar(' ');
			}
		}
		counter = counter + 2;
		mx_printchar('\n');
	}
}

