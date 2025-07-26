#include<stdio.h>
int sum_left_bottom(int *ptr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            sum+=*((ptr+i*n)+j);
        }
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("%d ",sum_left_bottom((int *)arr,n));

}