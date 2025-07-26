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
    
    int main_sum=0;
    int opposite_sum=0;
    for(int i=0;i<n;i++){
        main_sum+=matrix[i][i];
        opposite_sum+=matrix[i][n-1-i];
    }
    printf("Main Diagonal Sum= %d\nOpposite Diogonal Sum= %d",main_sum,opposite_sum);
    return 0;
}