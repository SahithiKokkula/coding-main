#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int k,a,b,x,y;
        cin>>k>>a>>b>>x>>y;
        int ans = 0;
        if (x>y){
            swap(x,y);
            swap(a,b);
        }
        if (x == y){
            if(a>b){
                swap(a,b);
            }
        }
        if(k >= a){
            int na = ceil((double)(k - a + 1) / x);
            ans+=na;
            k = k - x*na;
        }
        if(k >= b){
            int nb = ceil((double)(k - b + 1) / y);
            ans+=nb;
            k = k - x*nb;
        }
        cout<<ans<<endl;
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