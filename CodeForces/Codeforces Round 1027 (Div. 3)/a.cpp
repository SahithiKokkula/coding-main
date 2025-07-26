#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int year;
        cin>>year;
        int a = ceil(sqrt(year));
        if (a * a == year) cout<<a<<" "<<0<<endl;
        else cout<<-1<<endl;
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