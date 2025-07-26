#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int matrix[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }


    for(int k=0;k<n;k++){
        for(int i=0;i<m-1;i++){
            for(int j=0;j<m-i-1;j++){
                if(matrix[k][j]>matrix[k][j+1]){
                    int tmp=matrix[k][j];
                    matrix[k][j]=matrix[k][j+1];
                    matrix[k][j+1]=tmp;
                }
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(matrix[j][0]<matrix[j+1][0]){
                int tmp=matrix[j][0];
                matrix[j][0]=matrix[j+1][0];
                matrix[j+1][0]=tmp;
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}