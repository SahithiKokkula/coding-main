#include<iostream>
using namespace std;
int fibonacchi_recursion(int n){
    if (n==0||n==1){
        return n;
    }
    return fibonacchi_recursion(n-1)+fibonacchi_recursion(n-2);
}
int main(){
    cout<<fibonacchi_recursion(7);
    return 0;
}