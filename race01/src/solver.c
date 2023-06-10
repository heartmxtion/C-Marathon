#include <header.h>

void solver(char *operand1, char *operation, char *operand2, char *result,
                        int operand1_length, int operand2_length, int result_length) {
    long long num1 = mx_atoi(operand1);
    long long num2 = mx_atoi(operand2);
    long long num3 = mx_atoi(result);
    bool operand1_negative = false;
    bool operand2_negative = false;
    bool result_negative = false;
    if (*operation == '?') {
	    solver(operand1, "+", operand2, result, operand1_length, operand2_length, result_length);
	    solver(operand1, "-", operand2, result, operand1_length, operand2_length, result_length);
	    solver(operand1, "*", operand2, result, operand1_length, operand2_length, result_length);
	    solver(operand1, "/", operand2, result, operand1_length, operand2_length, result_length);
	    return;
    }

    if (operand1[0] == '-') {
	    operand1_negative = true;
	    operand1_length--;
	    operand1++;
    }
    
    if (operand2[0] == '-') {
	    operand2_negative = true;
	    operand2_length--;
	    operand2++;
    }

    if (result[0] == '-') {
	    result_negative = true;
	    result_length--;
	    result++;
    }
    for (long long i = 0; i < mx_pow(10, operand1_length); i++) {
        if (num1 > 0) {
            i = num1;
        }
        char *i_string = mx_itoa(i);
        int i_string_length = mx_strlen(i_string);
        bool isCorrectI = true;
        for (int i_i = 0; i_i < operand1_length - i_string_length; i_i++) {
            if (mx_isdigit(operand1[i_i]) && operand1[i_i] != '0') {
                isCorrectI = false;
                break;
            }
        }
        for (int i_i = operand1_length - i_string_length, i_string_i = 0; i_i < operand1_length; i_i++, i_string_i++) {
            if (operand1[i_i] != '?' && operand1[i_i] != i_string[i_string_i]) {
                isCorrectI = false;
                break;
            }
        }
        free(i_string);
        i_string = NULL;
        if (!isCorrectI) {
            continue;
        }
        for (long long j = 0; j < mx_pow(10, operand2_length); j++) {  
            if (num2 > 0) {
                j = num2;
            }
            char *j_string = mx_itoa(j);
            int j_string_length = mx_strlen(j_string);
            bool isCorrectJ = true;
            for (int j_i = 0; j_i < operand2_length - j_string_length; j_i++) {
                if (mx_isdigit(operand2[j_i]) && operand2[j_i] != '0') {
                    isCorrectJ = false;
                    break;
                }
            }
            for (int j_i = operand2_length - j_string_length, j_string_i = 0; j_i < operand2_length; j_i++, j_string_i++) {
                if (operand2[j_i] != '?' && operand2[j_i] != j_string[j_string_i]) {
                    isCorrectJ = false;
                    break;
                }
            }
            free(j_string);
            j_string = NULL;
            if (!isCorrectJ) {
                continue;
            }
            for (long long r = 0; r < mx_pow(10, result_length); r++) {
                if (num3 > 0) {
                    r = num3;
                }
                char *r_string = mx_itoa(r);
                int r_string_length = mx_strlen(r_string);
                bool isCorrectR = true;
                for (int r_i = 0; r_i < result_length - r_string_length; r_i++) {
                    if (mx_isdigit(result[r_i]) && result[r_i] != '0') {
                        isCorrectR = false;
                        break;
                    }
                }
                for (int r_i = result_length - r_string_length, r_string_i = 0; r_i < result_length; r_i++, r_string_i++) {
                    if (result[r_i] != '?' && result[r_i] != r_string[r_string_i]) {
                        isCorrectR = false;
                        break;
                    }
                }
                free(r_string);
                r_string = NULL;
                if (!isCorrectR) {
                    continue;
                }

		if (operand1_negative) {
			i *= -1;
		}

		if (operand2_negative) {
			j *= -1;
		}

		if (result_negative) {
			r *= -1;
		}
                if (*operation == '+') {
                    if (i + j == r) {
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(r);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '-') {
                        if (i - j == r) {
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(r);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '*') {
                        if (i * j == r) {
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(r);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '/') {
                    if (j != 0 && i / j == r) {
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(r);
                        mx_printchar('\n');
                    }
                }

		if (operand1_negative) {
			i *= -1;
		}

		if (operand2_negative) {
			j *= -1;
		}

		if (result_negative) {
			r *= -1;
		}
		if (num3 > 0){
			break;
		}
	    }
	    if (num2 > 0){
	    	break;
	    }
	}
	if(num1 > 0){
		break;
	}
    }
    
    if (operand1_negative) {
	    operand1--;
    }

    if (operand2_negative) {
	    operand2--;
    }

    if (result_negative) {
	    result--;
    }
}

