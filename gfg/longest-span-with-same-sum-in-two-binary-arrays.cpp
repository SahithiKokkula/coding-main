#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        int sum1 = 0 , sum2 = 0, diff = 0;
        map<int,int>mp;
        int ans = 0;
        for(int i = 0 ; i  < n  ; i++){
            sum1 += a1[i];
            sum2 += a2[i];
            
            diff = sum1 - sum2;
            if(diff == 0){
                ans = max(ans,i+ 1);
            }
            else if(mp.find(diff)!=mp.end()){
                ans = max(ans,i-mp[diff]);
            }
            else{
                mp[diff] = i;
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>a1 = {0, 1, 0, 1, 1, 1, 1};
    vector<int> a2= {1, 1, 1, 1, 1, 0, 1};
    cout<<solution.longestCommonSum(a1,a2);
    return 0;
}