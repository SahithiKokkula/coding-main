#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>freq(26,0);
        for(int i = 0; i < n ; i++){
            freq[s[i]-'a']++;
        }
        bool flag = false;
        for(int i = 1 ; i< n-1 ; i++){
            if(freq[s[i]-'a'] > 1){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
            return;
        }
        cout<<"No"<<endl;
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