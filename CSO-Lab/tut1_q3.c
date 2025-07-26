#include<stdio.h>
int main(){
    int m,n;
    printf("Enter rows and column of matrix:");
    scanf("%d %d",&m,&n);
    int mat[m][n];
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("Enter element for row %d and column %d:",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    int max=mat[0][0];
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (mat[i][j]>max){
                max=mat[i][j];
            }
        }
    }
    printf("%d",max);
}
