#include<stdio.h>
void matrixMultiply(int *matrix1, int *matrix2, int *result, int rows1, int cols1, int cols2) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            *(result + i * cols2 + j) = 0;
            for (k = 0; k < cols1; k++) {
                *(result + i * cols2 + j) += *(matrix1 + i * cols1 + k) * *(matrix2 + k * cols2 + j);
            }
        }
    }
}

void multiply_matrix(int* arr1,int *arr2, int* arr3,int n1,int m1,int m2){
    for (int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            int sum=0;
            for(int k=0;k<m1;k++){
                sum+=(*(arr1+k+i*m1))*(*(arr2+k*m2+j));
            }
            *(arr3+j+i*m2)=sum;
        }
    }
}
int main(){
    int n1,m1,n2,m2;
    scanf("%d %d",&n1,&m1);
    scanf("%d %d",&n2,&m2);
    int arr1[n1][m1];
    int arr2[n2][m2];
    int arr3[n1][m2];
    for(int i=0;i<n1;i++){
        for (int j=0;j<m1;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<n2;i++){
        for (int j=0;j<m2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    multiply_matrix(arr1,arr2,arr3,n1,m1,m2);
    for(int i=0;i<n1;i++){
        for (int j=0;j<m2;j++){
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
    matrixMultiply(arr1,arr2,arr3,n1,m1,m2);
    for(int i=0;i<n1;i++){
        for (int j=0;j<m2;j++){
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}