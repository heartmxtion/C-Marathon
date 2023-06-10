#include "header.h"

/*long long mx_atoi(const char *str) {
	long long result = 0;
	int index = 0;
	bool negative = false;
	
	while (str[index]) {
		if (mx_isspace(str[index])) {
			index++;
		}
		else {
			break;
		}
	}
	if (str[index] == '-' && mx_isdigit(str[index + 1])) {
		negative = true;
		index++;
	}
	if (str[index] == '+' && mx_isdigit(str[index + 1])) {
		index++;
	}
	while (mx_isdigit(str[index])) {
		result *= 10;
		result += index - '0';
		index++;
	}
	if (negative) {
		result *= -1;
	}
	return result;
}*/

int mx_atoi(const char *str) {
    bool is_negative = false;
    long int result = 0;
    int dod = 1;
    int begin = 0;
    int end;
    
    while (mx_isspace(str[begin]))
        begin++;
    if (str[begin] == '-') {
        is_negative = true;
        begin++;
    }
    else if (str[begin] == '+')
        begin++;
    end = begin;
    while (mx_isdigit(str[end]))
        end++;
    end--;
    for (int i = end; i >= begin; i--) {
        result += (str[i] - '0') * dod;
        dod *= 10;
    }
    if(is_negative)
        result = -result;
    
    if (result >= -2147483648 && result <= 2147483647)
        return result;
    return 0;
}

