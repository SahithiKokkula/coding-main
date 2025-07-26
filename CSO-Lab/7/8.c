#include<stdio.h>
int main(){
    

    int n1,m1;
    printf("Enter rows and column of matrix 1:");
    scanf("%d %d",&n1,&m1);
    int mat1[n1][m1];
    for (int i=0;i<n1;i++){
        for (int j=0;j<m1;j++){
            printf("Enter element for row %d and column %d:",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
    }
    int n2,m2;
    printf("Enter column of matrix 2:");
    scanf("%d %d",&n2,&m2);
    int mat2[n2][m2];
    for (int i=0;i<n2;i++){
        for (int j=0;j<m2;j++){
            printf("Enter element for row %d and column %d:",i+1,j+1);
            scanf("%d",&mat2[i][j]);
        }
    }
    char operator;
    printf("Enter the operator: ");
    scanf(" %c",&operator);
    
    switch ((int)operator){
        case ((int)'+') :
            if(n1==n2 && m1==m2){
                for(int i=0;i<n1;i++){
                    for(int j=0;j<m1;j++){
                        printf("%d ",mat1[i][j]+mat2[i][j]);
                    }
                }
            }
            else{
                printf("Not Possible");
            }
            break;
        case ((int)'-'):
            if(n1==n2 && m1==m2){
                for(int i=0;i<n1;i++){
                    for(int j=0;j<m1;j++){
                        printf("%d ",mat1[i][j]-mat2[i][j]);
                    }
                }
            }
            else{
                printf("Not Possible");
            }
            break;
        case ((int)'*') :
            if(m1==n2){
                int mul[n1][m2];
                for (int i=0;i<n1;i++){
                    for(int j=0;j<m2;j++){
                        int ans=0;
                        for (int k=0;k<m1;k++){
                            ans+=mat1[i][k]*mat2[k][j];
                        }
                        mul[i][j]=ans;
                    }
                }
                printf("\n");
                for (int i=0;i<n1;i++){
                    for (int j=0;j<m2;j++){
                        printf("%d ",mul[i][j]);
                    }
                    printf("\n");
                }
            }
            else{
                printf("Not Possible");
            }
            break;
    }
    return 0;
}