#include<bits/stdc++.h>
using namespace std;
int reverse_number(int x){
    int n=x;
    int rev=0;
    int i=0;
    while(n>0){
        if (rev>INT_MAX/10 || rev<INT_MIN/10){
            return 0;
        }
        rev=rev*10+(n%10);
        n=n/10;
    }
    if (n < 0 || rev != x) return 0;
    else return 1;
}
int main(){
    int x;
    cin>>x;
    cout<<reverse_number(x);
    return 0;
}