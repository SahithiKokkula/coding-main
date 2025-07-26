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
        int n,m;
        cin>>n>>m;
        vector<int>res(n+1,0);
        int a,b;
        for(int i = 0;i <m;i++){
            cin>>a>>b;
            res[max(a,b)] = max(res[max(a,b)],min(a,b));
        }
        int ans = 0;
        int len = 1;
        for(int i = 1;i<=n;i++){
            int newlen = i - res[i];
            len = min(len,newlen);
            ans+=len;
            len++;
        }
        cout<<ans<<endl;
    }
    return 0;
}