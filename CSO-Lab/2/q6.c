#include<stdio.h>
int main(){
    char operator;
    printf("Enter the operator: ");
    scanf("%c",&operator);
    switch (operator){
        case ((int)'+') :
            printf("Addition");
            break;
        case ((int)'-') :
            printf("Subtraction");
            break;
        case ((int)'*') :
            printf("Multiplication");
            break;
        case ((int)'/') :
            printf("Division");
            break;
        case ((int)'%') :
            printf("Modulus");
            break;
    }
    return 0;
}