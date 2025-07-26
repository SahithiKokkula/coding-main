#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string is a palindrome recursively
bool isPalindrome(char *str, int start, int end) {
    // Base case: if the start index is greater than or equal to the end index, it's a palindrome
    if (start >= end) {
        return true;
    }
    // If the characters at start and end positions are not equal, it's not a palindrome
    if (str[start] != str[end]) {
        return false;
    }
    // Recursively check the substring from start+1 to end-1
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);
    bool result = isPalindrome(str, 0, length - 1);

    if (result) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
