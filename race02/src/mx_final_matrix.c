#include "header.h"

char **final_matrix(char *res, int *row, int *col) {
    int temp_row = 0;
    int temp_col = 0;
    int i;

    for (i = 0; res[i] != '\0'; ++i) {
        if (res[i] == '\n')
            ++temp_row;
    }
    temp_col = (i - temp_row) / temp_row;

    char **mat = (char **)malloc(temp_row * 8);
    for (int i = 0; i < temp_row; i++) 
        mat[i] = (char *)malloc(temp_col);

    for (int i = 0; i < temp_row; ++i) {
        if (res[i] != '#' && res[i] != '.' && res[i] != ',' && res[i] != '\n') {
            mx_printerr("map error\n");
            exit(0);
        }
        for (int j = 0; j < temp_col; ++j) {
            if (res[j] != '#' && res[j] != '.' && res[j] != ',' && res[j] != '\n') {
                mx_printerr("map error\n");
                exit(0);
            }
            if (i == 0) {
                if (res[j] == '#')
                    mat[i][j] = '#';
                else if (res[j] == '.')
                    mat[i][j] = '.';
                else if (res[j] == ',' && res[j] != '\n') {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
            else {
                if (res[j + i * (temp_col + 1)] == '#')
                    mat[i][j] = '#';
                else if (res[j + i * (temp_col + 1)] == '.')
                    mat[i][j] = '.';
                else if (res[j + i * (temp_col + 1)] == ',' 
                    && res[j+ i * (temp_col + 1)] != '\n') {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
        }
    }

    *row = temp_row;
    *col = temp_col;
    return mat;
}

