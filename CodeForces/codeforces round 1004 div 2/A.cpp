#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x=0,y=0,sumx=0,sumy=0;
        cin>>x>>y;
        if (((y-x)==1) || (x>y && (x-y + 1)%9 == 0)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}