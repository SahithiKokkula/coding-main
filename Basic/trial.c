#include<stdio.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    // for(i=1;i<=n;i++){
    //     for(j=1;j<=2*n-1;j++){
    //         if(i>=j||i+j>=2*n){
    //             printf("* ");
    //         }
    //         else{
    //             printf("  ");
    //         }
    //     }
    //     printf("\n");
    // }
    for (int i =1;i<=n;i++){
        for (int j=1;j<=i;j++){
            printf("*");
        }
        
    }
return 0;
}