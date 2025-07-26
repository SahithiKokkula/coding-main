#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&v,int n){
    if (n<=1) return 1;
    if (v[n]!=-1) return v[n];
    return v[n] = f(v,n-1)+f(v,n-2);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n+1,-1);
    cout<<f(v,n);
    return 0;
}