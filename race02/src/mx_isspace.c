#include "header.h"

bool mx_isspace(char c) {
    switch (c) {
    case ' ':
        return true;
    case '\t':
        return true;
    case '\n':
        return true;
    case '\v':
        return true;
    case '\f':
        return true;
    case '\r':
        return true;
    default:
        return false;
    }
}

