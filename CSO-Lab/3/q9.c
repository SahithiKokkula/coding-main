#include<stdio.h>
#include<math.h>
int main(){
    float val;
    int choise;
    printf("Enter the value to compute: ");
    scanf("%f",&val);
    printf("\nEnter 1 for Sin.\nEnter 2 for Cosin.\nEnter any other value for tan.\nEnter your choise: ");
    scanf("%d",&choise);
    if(choise==1) printf("Sine of the value is: %f",sin(val));
    else if(choise==2) printf("Cosine of the value is: %f",cos(val));
    else printf("Tan of the value is: %f",tan(val));
    return 0;
}