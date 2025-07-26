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


    int trace=0;
    for(int i=0;i<n;i++){
        trace+=matrix[i][i];
    }
    printf("trace = %d\n",trace);

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            int tmp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=tmp;
        }
    }
    printf("Transpose: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}