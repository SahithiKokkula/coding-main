#include<stdio.h>
int n,m;
int n1,n2,n3,m1,m2,m3;
void enter_matrix(int mat[n][m]){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter element for row %d and column %d:",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    return;
}
void multiply_matrix(int mul[n1][m2],int mat1[n1][m1],int mat2[n2][m2]){
    for (int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            int ans=0;
            for (int k=0;k<m1;k++){
                ans+=mat1[i][k]*mat2[k][j];
            }
            mul[i][j]=ans;
        }
    }

}
void display_matrix(int mat[n][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d " ,mat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    // Matrix-1
    printf("Enter rows and column of matrix 1:");
    scanf("%d %d",&n,&m);
    int mat1[n][m];
    enter_matrix(mat1);
    n1=n;
    m1=m;
    // Matrix-2
    printf("Enter rows and column of matrix 2:");
    scanf("%d %d",&n,&m);
    int mat2[n][m];
    enter_matrix(mat2);
    n2=n;
    m2=m;
    // Matrix-3
    printf("Enter rows and column of matrix 3:");
    scanf("%d %d",&n,&m);
    int mat3[n][m];
    enter_matrix(mat3);
    n3=n;
    m3=m;
    // Multiply 1 and 2
    int mul1[n1][m2];
    multiply_matrix(mul1,mat1,mat2);
    m1=m2;
    n2=n3;
    m2=m3;
    // multiply 2 and 3
    int mul2[n1][m2];
    multiply_matrix(mul2,mul1,mat3);
    n=n1;
    m=m3;
    // Display matrix
    display_matrix(mul2);
    return 0;
}