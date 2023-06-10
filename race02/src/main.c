#include "header.h"

int main(int argc, char *argv[]){
	if (argc != 6) {
		mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
		exit(0);
	}
	int src = open(argv[1], O_RDONLY);
	if (src < 0) {
		mx_printerr("map does not exist\n");
		exit(0);
	}
	bool first_time = true;
	int temp_col_max;
	int temp_col = 0;
	char buf;
	while (read(src, &buf, 1)) {
		if (buf != '#' && buf != '.' && buf != ',' && buf != '\n') {
			mx_printerr("map error\n");
			exit(-1);
		}
		if(buf == ',') continue;
		if(buf == '\n') {
			if(first_time){
				first_time = false;
				temp_col_max = temp_col;
			}
			else{
				if(temp_col_max != temp_col){
					mx_printerr("map error\n");
					exit(-1);
				}
				
			}
			temp_col = 0;
			continue;
		}
		temp_col++;
	}

	/*char s[1];
	int n = read(src, s, 4);
	if (n <= 0) {
		mx_printerr("map does not exist\n");
		exit(0);
	}*/

	int col, row, len;
	int x1 = mx_atoi(argv[2]), x2 = mx_atoi(argv[4]);
	int y1 = mx_atoi(argv[3]), y2 = mx_atoi(argv[5]);
	char *str = mx_file_to_str(argv[1]);
	int **matrix1 = matrix(str, &row, &col);
	int **matrix2 = matrix(str, &row, &col);
	char **final = final_matrix(str, &row, &col);

	if (x1 >= col || x2 >= col || x1 < 0 || x2 < 0 
		|| y1 < 0 || y2 < 0 || y1 >= row|| y2 >= row) {
		mx_printerr("points are out of map range\n");
		exit(0);
	}
	int path_X[row * col], path_Y[row * col];
	if (!mx_lee(matrix1, x1, y1, x2, y2, row, col, &len, path_X, path_Y)) {
        	mx_printerr("route not found\n");
		exit(0);
	}
	int file1 = open("path.txt", O_WRONLY);
	if (file1 < 0) {
        	file1 = open("path.txt", O_CREAT | O_WRONLY);
        }
	for (int i = 0; i < len ; i++) {
            final[path_Y[i]][path_X[i]] = '*';
        }
	final[y2][x2] = '*';
	max(matrix2, x1, y1, row, col, final);
	for (int i = 0; i < row ; i++) {
		for (int j = 0; j < col; j++) {
			char s = final[i][j];
			write(file1, &s, 1);
		}
		write(file1, "\n", 1);
	}
	if (close(file1) < 0) {
		mx_printerr("map error\n");
		exit(0);
	}
	mx_printstr("dist=");
	mx_printint(max(matrix2, x1, y1, row, col, final));
	mx_printstr("\n");
	mx_printstr("exit=");
	mx_printint(len);
	mx_printstr("\n");
	return 0;
}

