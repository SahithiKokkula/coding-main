#include<bits/stdc++.h>
using namespace std;
bool print_divisors(int n){
    if (n==1) return 0;
    for (int i=1;i<=pow(n,0.5);i++){
        if (n%i==0){
            if(i==1||i==n) continue;
            else return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    cout<<print_divisors(n);
    return 0;
}