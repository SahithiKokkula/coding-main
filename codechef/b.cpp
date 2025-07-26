#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        int num;
        cin>>num;
        if (n == 1) {
            cout<<-1<<endl;
            return;
        }
        int prev_ele = num;
        for(int i = 1 ; i < n ; i++){
            cin>>num;
            if (prev_ele != num){
                cout<<2<<endl;
                return;
            }
            prev_ele = num;
        }
        cout<<-1<<endl;
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