#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        int s;
        cin>>n>>s;
        int num;

        int x1 ,x2;
        for(int i = 0 ; i < n ; i++){
            cin>>num;
            if(i == 0) x1 = num;
            if(i == n-1) x2 = num;
        }
        int diff = min(abs(x2-s),abs(s-x1));
        cout<<x2-x1+diff<<endl;
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