#include<stdio.h>
int fac(int n){
    if(n==0) return 1;
    return n*fac(n-1);
}
int ncr_ans=1;
int ncr(int n,int r){
    ncr_ans=fac(n)/(fac(r)*fac(n-r));
    return ncr_ans;
}
int main(){
    int n;
    printf("Enter number of rows: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<i+1;j++){
            printf("%d ",ncr(i,j));
        }
        printf("\n");
    }
    return 0;
}