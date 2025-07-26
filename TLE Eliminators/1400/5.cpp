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
        vector<int>a(n);
        vector<int>b(n);
        a[0] = m;
        for(int i = 1 ;i < n ;i++){
            cin>>a[i];
        }
        
        for(int i = 0 ;i < n ;i++){
            cin>>b[i];
        }
        int i = 0,j=0;
        int ans = 0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(i<n && j<n){
            if (a[i] < b[j]){
                i++;
                j++;
            }
            else{
                ans++;
                j++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}