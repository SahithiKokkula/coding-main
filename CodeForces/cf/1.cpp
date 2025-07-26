#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int a,x,y;
        cin>>a>>x>>y;
        if(x>y) swap(x,y);
        if(x<a && y > a){
            cout<<"No"<<endl;
            return;
        }
        cout<<"yes"<<endl;
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        solution.solve();
    }
    return 0;
}