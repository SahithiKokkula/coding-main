#include<bits/stdc++.h>
using namespace std;

int count_digits(int n) {
    if (n == 0) {
        return 1; 
    }
    return floor(log10(n)) + 1; 
}

int main(){
    long x,y;
    long k = 0;
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int ans=0;
        int a = count_digits(y) - count_digits(x);
        if (x*pow(10,a)>y) a = a - 1;
        int num = x*pow(10,a);
        int rem = floor(y/num);
        ans+=rem;
        y = y - num * rem;
        rem = floor(y / x);
        ans += rem;
        y = y - x * rem;
        ans += y;
        cout<<ans;
    }

}