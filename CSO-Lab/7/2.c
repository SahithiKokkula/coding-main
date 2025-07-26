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


    int freq=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]%2==0){
                freq++;
            }
        }
    }
    

    printf("%d",freq);
    return 0;
}