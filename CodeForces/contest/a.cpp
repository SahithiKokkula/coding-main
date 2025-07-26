#include<bits/stdc++.h>
using namespace std;
class Solution{

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        int n,m,p,q;
        cin>>n>>m>>p>>q;
        if (n%p == 0 && q*(n/p) != m){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}