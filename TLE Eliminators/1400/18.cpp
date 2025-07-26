#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n ;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        int cnt = 0;
        int mini = *min_element(arr.begin(),arr.end());
        for(auto it :arr){
            if (it == mini) cnt ++;
            else if((it&mini )!= mini){
                cout<<0<<endl;
                return;
            }
        }
        int MOD = 1e9 + 7;
        int ans = 1;
        int fact = 1;
        for(int i = 1 ;i <= n-2;i++) fact =(1LL * fact * i) % MOD;
        ans = (1LL * ans * cnt) % MOD;
        ans = (1LL * ans * (cnt-1)) % MOD;
        ans = (1LL * ans * fact) % MOD;
        cout<<ans<<endl;
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