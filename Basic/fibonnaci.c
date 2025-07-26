// #include<stdio.h>
// int fibonnaci(int n){
//     int a=0;
//     int b=1;
//     for(int i=0;i<n;i++){
//         printf("%d ",a);
//         b=b+a;
//         a=b-a;
//     }
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     fibonnaci(n);
// }


#include<stdio.h>
int fibonacchi_recursion(int n){
    if (n==0||n==1){
        return n;
    }
    return fibonacchi_recursion(n-1)+fibonacchi_recursion(n-2);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fibonacchi_recursion(n));
    return 0;
}