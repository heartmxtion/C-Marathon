#include <header.h>

bool mx_isspace(char c);
long long mx_atoi(const char *str) {
        int start = -1;
        int end = -1;
        int minus = 0;
        int res = 0;
        for (int i = 0; str[i] != '\0'; i++) {
                if ((str[i] == '-')
                     && (mx_isdigit(str[i + 1]) == true)) {
                        minus = 1;
                        continue;
                }
                if ((mx_isspace(str[i]) == false)
                     && (start == -1))
                        start = i;
                if ((start > -1)
                     && (mx_isdigit(str[i]) == false)
                     && (end == -1))
                        end = i;
        }
        if (end == -1) {
                for (int i = start; str[i] != '\0'; i++)
                        res = 10 * res + (int)str[i] - 48;
        }
        else {
                for (int i = start; i < end; i++)
                        res = 10 * res + (int)str[i] - 48;
        }
        return minus == 0 ? res : -1 * res;
}

