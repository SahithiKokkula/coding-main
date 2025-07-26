#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long l,r;
    while(t--){
        cin>>l>>r;
        if (l==r && l == 1){
            cout<<1<<endl;
        }
        else{
            cout<<r-l<<endl;
        }
    }
}