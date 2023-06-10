#pragma once

#include "stdio.h"
#include "fcntl.h"
#include "stdbool.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"

int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
void mx_strdel(char **str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
int **matrix(char *res, int *row, int *col);
char **final_matrix(char *res, int *row, int *col);
bool mx_lee(int **maze, int ax, int ay, int bx, int by, int Height, int Width, int *len, int *path_X, int *path_Y);
int max(int **array,int ax, int ay,int Height, int Width, char **final);
char *mx_file_to_str(const char *filename);
char *mx_strtrim(const char *str);

