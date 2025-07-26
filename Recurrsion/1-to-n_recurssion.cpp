#include<iostream>
using namespace std;
void number(int n,int s){
    if (s==n+1) return ;
    cout<<s<<" ";
    number(n,s+1);
}
void number1(int n){
    if (n==0) return ;   
    number1(n-1);
    cout<<n<<" ";
}
int main(){
    number1(10);
    return 0;
}