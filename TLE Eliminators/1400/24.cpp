#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        vector<int>arr(n);
        int num;
        for(int i = 0 ; i < n ; i++){
            cin>>num;
            arr[i] = num;
        }
        long long prev_pos = 0;
        long long prev_neg = 0;
        long long total_pos = 0;
        long long total_neg = 0;
        for(int i = n - 1; i >= 0; i--){
            if (arr[i] > 0){
                prev_pos += 1;
                total_neg += prev_neg;
                total_pos += prev_pos;
            }
            else{
                swap(prev_neg,prev_pos);
                prev_neg += 1;
                total_neg += prev_neg;
                total_pos += prev_pos;
            }
        }
        cout<<total_neg<<" "<<total_pos;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    solution.solve();
    return 0;
}