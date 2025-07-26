#include<stdio.h>
int main(){
    int marks;
    printf("Enter the marks: ");
    scanf("%d",&marks);
    printf("Grade: ");
    if(marks>90) printf("A");
    else if(marks>80) printf("A-");
    else if(marks>70) printf("B");
    else if(marks>60) printf("B-");
    else if(marks>50) printf("C");
    else if(marks>40) printf("C-");
    else printf("F");

    return 0;
}