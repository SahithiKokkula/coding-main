#include<iostream>
using namespace std;
void multiples(int num,int k){
    if (k<1) return;
    multiples(num,k-1);
    cout<<num*k<<" ";
}
int main(){
    multiples(2,10);
    return 0;
}