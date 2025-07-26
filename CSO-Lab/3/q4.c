#include<stdio.h>
#include<complex.h>
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
    float complex sqrtD;
    if(D>=0) sqrtD=sqrt(D);
    else sqrtD = sqrt(-D)*I;
    float complex sol1=(-b+sqrtD)/(2*a);
    float complex sol2=(-b-sqrtD)/(2*a);
    if(D>=0){
        printf("Solution 1 = %f\n",creal(sol1));
        printf("Solution 2 = %f",creal(sol2));
    }
    else {
        if(cimag(sol1)>0){
            printf("Solution 1 =%f + %fi\n",creal(sol1),cimag(sol1));
            printf("Solution 2 =%f - %fi",creal(sol1),cimag(sol1));
        }
        else{
            printf("Solution 1 =%f + %fi\n",creal(sol1),-cimag(sol1));
            printf("Solution 2 =%f - %fi",creal(sol1),-cimag(sol1));
        }
    }
    return 0;
}