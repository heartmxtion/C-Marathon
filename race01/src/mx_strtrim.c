#include <header.h>

char *mx_strtrim(const char *str){
    if(str == NULL){
    	return NULL;
    }
    int size = 0, count_left = 0, count_right = 0;
    while(*str){
        size++;
        str++;
    }
    str -= size;
    while(*str && mx_isspace(*str)){
        str++;
        count_left++;
    }
    str -= count_left;
    for(int i = size - 1; i >= count_left; i--){
        if(!mx_isspace(str[i])){
        	break;
	}
        count_right++;
    }
    char *arr = mx_strnew(size - count_left - count_right);
    for(int i = count_left, j = 0; i <= size - 1 - count_right; i++, j++){
        arr[j] = str[i];
    }  
    return arr;
}

