#include<stdio.h>
int divideit(int n){
    if (n==2 || n%2!=0) return 0;
    return 1;

}
int main(){
    int n;
    scanf("%d",&n);
    if (divideit(n)){
        printf("YES");
    }
    else{
        printf("NO");
    }
}