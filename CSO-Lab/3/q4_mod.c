#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    printf("Quadratic equation is in the format aX^2+bX+C=0\n");
    printf("Enter a i.e coeffcient of X^2: ");
    scanf("%f",&a);
    printf("Enter b i.e coeffcient of X: ");
    scanf("%f",&b);
    printf("Enter c i.e constant term: ");
    scanf("%f",&c);
    float D=b*b-4*a*c;
    float sqrtD;
    if(D>=0){
        sqrtD=sqrt(D);
        float sol1=(-b+sqrtD)/(2*a);
        float sol2=(-b-sqrtD)/(2*a);
        printf("Solution 1 = %f\n",sol1);
        printf("Solution 2 = %f",sol2);
    }
    else{
        sqrtD = sqrt(-D);
        float real=-b/(2*a);
        float complex= sqrtD/(2*a);
        printf("Solution 1 =%f + %fi\n",real,complex);
        printf("Solution 2 =%f - %fi",real,complex);
    }
    return 0;
}