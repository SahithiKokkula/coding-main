// #include<stdio.h>
// int main(){
//     int b = 20;
//     int k = 35;
//     int a = 1;
//     scanf("%d",&k);
//     printf("%d %d",k,a);
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main() {
    char name[10]; 
    char age[5]; 

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter your age: ");
    fgets(age, sizeof(age), stdin);

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);

    return 0;
}