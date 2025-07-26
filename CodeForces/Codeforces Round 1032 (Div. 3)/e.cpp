#include<bits/stdc++.h>
using namespace std;
class Solution{
private: 
int f(int l,int x,int r){
    int c = 0;
    while(l>0 || x > 0 || r> 0){
        if(l%10 == x%10) c++;
        if(r%10 == x%10) c++;
        l = l/10;
        r= r/10;
        x= x/10;
    }
    return c;

}
public:
    void solve(){
        int l,r;
        cin>>l>>r;

        int ans = INT_MAX;

        for(int i = l ; i <= r ;i++){
            ans = min(ans,f(l,i,r));
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