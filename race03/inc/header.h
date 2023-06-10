#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>

struct colms{
	wchar_t *arr;
	int length, start, finish;
};

wchar_t get_rain_symbols();
void term_size(WINDOW *mainwin,int *row, int *col);
int matrix(WINDOW *mainwin);
void print_massege(WINDOW *mainwin, int col, int row);

