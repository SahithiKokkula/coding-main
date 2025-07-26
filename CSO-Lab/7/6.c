#include<stdio.h>
int main(){
    int n,m;
    scanf("%d ",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int check=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j && matrix[i][j]!=1){
                check=1;
                break;
            }
            else if(i!=j && matrix[i][j]!=0){
                check=1;
                break;
            }
        }
    }
    
    if(check==0){
        printf("Identity Matrix");
    }
    else{
        printf("Not Identity");
    }
    return 0;
}