#include<stdio.h>
int main(){
    int n,m,o;
    scanf("%d %d %d",&n,&m,&o);
    int matrix[n][m][o];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<o;k++){
                scanf("%d",&matrix[i][j][o]);
            }
        }
    }


    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            int tmp=matrix[0][i][j];
            matrix[0][i][j]=matrix[2][i][j];
            matrix[2][i][j]=tmp;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            int tmp=matrix[i][1][j];
            matrix[i][1][j]=matrix[i][3][j];
            matrix[i][3][j]=tmp;
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