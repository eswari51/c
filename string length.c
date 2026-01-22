#include <stdio.h>

int main() {
    char str[100];
    int len = 0;

    printf("Enter a string: ");
    gets(str);   // for beginners only

    while (str[len] != '\0')
        len++;

    printf("Length = %d", len);
    return 0;
}
