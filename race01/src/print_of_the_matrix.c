#include <header.h>

int main(int argc, char *argv[]){
    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
        exit(1);
    }
    char *operand1 = mx_strtrim(argv[1]);
    char *operation = mx_strtrim(argv[2]);
    char *operand2 = mx_strtrim(argv[3]);
    char *result = mx_strtrim(argv[4]);
    int operand1_length = mx_strlen(operand1);
    int operation_length = mx_strlen(operation);
    int operand2_length = mx_strlen(operand2);
    int result_length = mx_strlen(result);
    supervisor_lenght_check(argv, operand1_length,
				operation_length, operand2_length, result_length);
    supervisor(argv, operand1, operation, operand2, result, 
                operand1_length, operand2_length, result_length);
    solver(operand1, operation, operand2, result, 
                operand1_length, operand2_length, result_length);
    free(operand1);
    operand1 = NULL;
    free(operation);
    operation = NULL;
    free(operand2);
    operand2 = NULL;
    free(result);
    result = NULL;
    return 0;
}

