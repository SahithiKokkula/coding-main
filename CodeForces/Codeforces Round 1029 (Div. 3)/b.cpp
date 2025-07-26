#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int num = 1; num <=n ;num = num+2){
            cout<<num<<" ";
        }
        if((n&1 )== 1) n = n-1;
        for(int num = n ; num>=2;num = num-2){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}