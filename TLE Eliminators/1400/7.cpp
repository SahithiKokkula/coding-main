#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(string s,int n){
        int state1 = 0;
        int state2 = 0;
        vector<int>ans(n);
        int one = 0;
        int two = 0;
        for(int i = 0;i <n;i++){
            if (s[i] == '('){
                if (state2){
                    --state2;
                    ans[i] = 2;
                    two = 1;
                }
                else{
                    state1++;
                    ans[i]= 1;
                    one = 1;
                }
            }
            if (s[i] == ')'){
                if (state1){
                    --state1;
                    ans[i] = 1;
                    one = 1;
                }
                else{
                    state2++;
                    ans[i]= 2;
                    two = 2;
                }
            }
        }
        if (state1 || state2) {
            cout<<-1<<endl;
            return;
        }
        cout<<one+two<<endl;
        if (one + two == 1){
            for(int i = 0; i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
            return;
        }
        for(auto it:ans){
            cout<<it<<" ";
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
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solution.solve(s,n);
    }
    return 0;
}