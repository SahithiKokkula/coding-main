#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {

    int length = strlen(str);
    if (length <= 1) 
        return;

    char *start = str;
    char *end = str + length - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];
    gets(str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
