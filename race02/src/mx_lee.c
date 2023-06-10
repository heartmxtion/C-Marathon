#include "header.h"

bool mx_lee(int **maze, int ax, int ay, int bx, int by, int Height, int Width, int *len, int *path_X, int *path_Y) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool end;
    int dist = 0;
    int x;
    int y;
    int k;

    if (maze[ay][ax] == -1) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }
    if (maze[by][bx] == -1) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(0);
    }
    maze[ay][ax] = 0;

    while (true) {
        end = true;
        for (y = 0; y < Height; ++y) {
            for (x = 0; x < Width; ++x) {
                if (maze[y][x] == dist) {
                    for (k = 0; k < 4; ++k) {
                        int index_y = dy[k] + y;
                        int index_x = dx[k] + x;
                        if (index_y >= 0 && index_y < Height && index_x >= 0 
                            && index_x < Width && maze[index_y][index_x] == -2) {
                            end = false;
                            maze[index_y][index_x] = dist + 1;
                        }
                    }
                }
            }
        }
        dist++;
        if (end || maze[by][bx]!= -2)
            break;
    }
    if (maze[by][bx] == -2)
        return false;

    *len = maze[by][bx];
    y = by;
    x = bx;
    dist = *len;

    while (dist > 0) {
        path_X[dist] = x;
        path_Y[dist] = y;
        dist--;
        for (k = 0; k < 4; ++k) {
            int index_y = dy[k] + y;
            int index_x = dx[k] + x;
            if (index_y >= 0 && index_y < Height && index_x >= 0
                && index_x < Width && maze[index_y][index_x] == dist) {
                y = y + dy[k];
                x = x + dx[k];
                break;
            }
        }
    } 

    path_Y[0] = ay;
    path_X[0] = ax;

    return true;
}

