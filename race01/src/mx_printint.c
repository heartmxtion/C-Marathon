#include <header.h>

void mx_printint(int n){
	char c[12];
	int i = 0;
	if(n == 0){
		mx_printchar('0');
	}
	if(n < 0){
		if(n == -2147483648){
			write(1, "-2147483648", 11);
		}
		else{
			mx_printchar('-');
		}
	}
	while(n != 0) {
		if(n > 0){
			c[i++] = '0' + n % 10;
		}
		else{
			c[i++] = '0' + n%10*(-1);
		}
		n /= 10;
	}
	i -= 1;
	while(i >= 0){
		mx_printchar(c[i]);
		i--;
	}
}

