#include<iostream>
using namespace std;
// Method-1
int f1(int n,int sum=0){
    if (n==0) return sum;
    (n%2==0)?(sum-=n):(sum+=n);
    f1(n-1,sum);
}
// Method-2
int f2(int n){
    if (n==0) return 0;
    return f2(n-1) + ((n%2==0)?(-n):(n));
}
int main(){
    cout<<f1(3)<<endl;
    cout<<f2(3);
    return 0;
}