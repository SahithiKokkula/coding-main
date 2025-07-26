#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>sums(n,0);
        map<int,int>mp;
        int maxSum = 0;
        int i = 0;
        int j = -1;
        for (int i = 0 ;i< n ;i++){
            sums[i] = nums[i] + ((i > 0) ? sums[i-1] : 0);
            if(mp.find(nums[i]) != mp.end()){
                j = (mp[nums[i]] > j ) ? mp[nums[i]]:j;
                maxSum = max(maxSum,sums[i] - sums[j]);
                mp[nums[i]] = i;
            }
            else{
                maxSum = max(maxSum,sums[i] - (j == -1 ? 0 : sums[j]));
                mp[nums[i]] = i;
            }
        }
        return maxSum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {5,2,1,2,5,2,1,2,5};
    cout<<solution.maximumUniqueSubarray(nums);
    return 0;
}