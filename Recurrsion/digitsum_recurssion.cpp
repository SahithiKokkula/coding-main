#include<iostream>
using namespace std;
int digitsum(int n){
    if(n==0) return 0;
    return n%10+digitsum(n/10);
}
int main(){
    cout<<digitsum(9);
    return 0;
}