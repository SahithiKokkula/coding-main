// #include<stdio.h>
// int main(){
//     char string[1000];
//     gets(string);
//     char c;
//     int i=0;
//     while((c=string[i++])!='\0'){
//         char substr[50];
//         int j=0;
//         if(c!=' '){
//             substr[j++]=c;
//             while((c=string[i++])!='\0' && c != ' '){
//                 substr[j++]=c;
//             }
//         }
        
//         puts(substr);
//         printf("\n");

//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

void splitWords(char *sentence, char **words) {
    char *token;
    int index = 0;

    token = strtok(sentence, " ");
    
    while (token != NULL) {
        words[index] = token;
        index++;
        token = strtok(NULL, " ");
    }
}

int main() {
    char sentence[MAX_WORD_LEN * MAX_WORDS];
    char *words[MAX_WORDS];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Removing trailing newline character
    if (sentence[strlen(sentence) - 1] == '\n')
        sentence[strlen(sentence) - 1] = '\0';

    splitWords(sentence, words);

    printf("Words in the sentence:\n");
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
