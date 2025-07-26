#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i)
            printf("%d ",matrix[i][j]);
            else
            printf("  ");
        }
        printf("\n");
    }
    return 0;
}