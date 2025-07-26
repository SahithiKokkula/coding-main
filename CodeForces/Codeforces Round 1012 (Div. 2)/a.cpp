#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,a;
        cin>>x>>y>>a;
        int loops = a /(x+y);
        a -= loops*(x+y);
        cout<<((a>=x)?"YES":"NO")<<endl;
    }
}