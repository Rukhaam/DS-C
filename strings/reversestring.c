#include <stdio.h>

void reverseString(char str[]) {
    int len = 0;
    char revStr[100];

    while (str[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        revStr[i] = str[len - 1 - i];
    }
    revStr[len] = '\0';

    printf("%s\n", revStr);
}

int main() {
    char str[100] = "dad";
    reverseString(str);
    return 0;
};