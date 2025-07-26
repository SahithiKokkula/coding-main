#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        vector<int>p(n,0);
        vector<int>q(n,0);
        int num = 0;
        int prev_num = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>num;
            num = pow(2,num);
            p[i] = prev_num = max(num,prev_num);
        }
        prev_num = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>num;
            num = pow(2,num);
            q[i] = prev_num = max(num,prev_num);
        }
        for(int i = 0 ; i < n ; i++){
            cout<<p[i]<<" "<<  q[i]<<" ";
        }
        cout<<endl;
        return;

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while (t--){
        solution.solve();
    }
    
    return 0;
}