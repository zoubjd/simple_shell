#include "shell.h"

int _atoi(char* str) {
    int res = 0;
    int i = 0;

    // Process digits
    while (str[i] != '\0') {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return res;
}
