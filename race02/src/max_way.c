#include "header.h"

int max(int **array,int ax, int ay,int Height, int Width, char **final) {
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int x, y, a = 0, k;
	bool stop = false;
	int maximum;
	int flag = 1;
	array[ay][ax] = 0;
	while (!stop  || flag) {
		stop = true;
		for (y = 0; y < Height; ++y) {
			for (x = 0; x < Width; ++x) {
				if (array[y][x] == a) {
					for (k = 0; k < 4; ++k) {
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < Height && ix >= 0 && ix < Width &&
							array[iy][ix] == -2) {
							stop = false;
							array[iy][ix] = a + 1;
						}
					}
				}
			}
		}
		a++;
		flag = 0;
	}
	maximum = array[0][0];
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			if (array[i][j] > maximum) {
				maximum = array[i][j];
			}
        }
	}
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			if (array[i][j] == maximum) {
				if (final[i][j] == '*') {
					final[i][j] = 'X';
				}
				else final[i][j] = 'D';
			}
		}
	}
	return maximum;
}

