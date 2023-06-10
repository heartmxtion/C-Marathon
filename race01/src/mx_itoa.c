#include <header.h>

char *mx_itoa(long long number){
    char *num_str = NULL;
    int length = 0;
    long long num_copy = number;
    if(number == 0){
        num_str = mx_strnew(1);
        num_str[0] = '0';
        return num_str;
    }
    if(num_copy < 0){
        length++;
        num_copy *= -1;
    }
    while(num_copy != 0){
        num_copy /= 10;
        length++;
    }
    num_str = mx_strnew(length);
    if(number < 0){
        num_str[0] = '-';
        number *= -1;
    }
    num_str[length--] = '\0';
    while((number != 0 && length >= 0) && num_str[length] != '-'){
        num_str[length--] = (number % 10) + '0';
        number /= 10;
    }
    return num_str;
}

