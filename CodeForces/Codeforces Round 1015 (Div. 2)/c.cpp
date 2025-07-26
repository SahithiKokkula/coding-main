#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        vector<pair<int,int>>result;
        int m= 0;
        int n;
        cin>>n;
        int index;
        vector<int>a(n);
        vector<int>b(n);
        vector<int>hash(n+1);
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>b[i];
            hash[b[i]] = i;
            if (a[i] == b[i]) {
                count++;
                index = i;
            }
        }
        if ((count >= 2) || (count == 1 && n&1 != 1)){
            cout<<-1<<endl;
            return;
        }
        else{
            if (count == 1 ){
                if (index == n/2){
                    cout<<0<<endl;
                    return;
                }
                swap(a[index],a[n/2]);
                swap(b[index],b[n/2]);
                swap(hash[b[index]],hash[b[n/2]]);
                result.push_back({index+1,n/2+1});
                m++;
                
            }
            int i = 0;
            int j = n-1;
            while(i<=n/2){
                if (a[i] != b[j]){
                    int idx1 = j;
                    int idx2 = hash[a[i]];
                    result.push_back({idx1+1,idx2+1});
                    swap(b[idx1],b[idx2]);
                    swap(hash[b[idx1]],hash[b[idx2]]);
                    m++;
                    
                i++;
                j--;
                }
                else{
                    
                i++;
                j--;
                }
            }
        }
        cout<<m<<endl;
        for(auto it : result){
            cout<<it.first<<" "<<it.second<<endl;
        }
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    
    Solution solution;
    while(t--){
        solution.solve();
    }
    return 0;
}