#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if ((n&1) == 1 ){
            for(int i = 1; i <= n ; i +=2){
                cout<<i<<" ";
            }
            for(int  i = 2 ; i <= n ; i+=2){
                cout<<i<<" ";
            }
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}