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
    
    matrix[n/2][n/2]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                matrix[i][j]--;
            }
            if(i>j){
                matrix[i][j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}