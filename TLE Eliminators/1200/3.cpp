#include<bits/stdc++.h>
using namespace std;
long long findHCF(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long findlcm (long long a,long long b){
    return a*b/findHCF(a,b);
}
int main(){
    int t;
    cin>>t;
    while (t--){
        long long n,x,y;
        cin>>n>>x>>y;
        long long lcm = findlcm(x,y);
        long long lcmfac = n/lcm;
        long long xfac = n/x - lcmfac;
        long long yfac = n/y - lcmfac;
        long long sumx = n*(n+1)/2 - (n-xfac)*(n-xfac+1)/2;
        long long sumy = yfac*(yfac+1)/2;
        cout<<sumx-sumy<<endl;
    }
    
}