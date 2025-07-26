#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void solve(){
        int n;
        cin>>n;
        vector<int>arr(n);
        int num;
        for(int i = 0 ; i < n ; i ++){
            cin>>num;
            arr[i] = num;
        }
        int i = 0;
        while(i + 1 < n){
            if(abs(arr[i] - arr[i + 1]) <=1 ){
                cout<<0<<endl;
                return;
            }
            if (i > 0){
                int prev_num = arr[i-1];
                if(prev_num >= (min(arr[i],arr[i + 1]) - 1) && prev_num <= (max(arr[i],arr[i + 1]) + 1)){
                    cout<<1<<endl;
                    return;
                }
            }
            if(i + 1 + 1 < n){
                int next_num = arr[i + 1+1];
                if (abs(arr[i + 1] - arr[i + 1+1]) <= 1){
                    cout<<0<<endl;
                    return;
                }
                if(next_num >= (min(arr[i],arr[i + 1]) - 1) && next_num <= (max(arr[i],arr[i + 1]) + 1)){
                    cout<<1<<endl;
                    return;
                }
            }
            i++;
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