#include<bits/stdc++.h>
using namespace std;

    void solve(){
        vector<int>fibonachi={0,1,2,3,5,8,13,21,34,55,89,144};
        int n , m;
        cin>>n>>m;
        string ans="";
        int c1 = fibonachi[n];
        int c2 = fibonachi[n+1];
        for(int i = 0 ; i < m ; i++){
            int l,b,h   ;
            char check = '0';
            cin>>l>>b>>h    ;
            if((l >= c1 && b>= c1 && h   >= c1) && (l>=c2 || b>=c2 || h   >=c2)) check = '1';
            ans+=check;
        }
        cout<<ans<<endl;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}