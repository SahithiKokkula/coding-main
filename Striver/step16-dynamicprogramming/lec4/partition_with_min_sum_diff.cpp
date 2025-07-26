// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// private:
//     int sol1(vector<int>&nums,int i, int k1,int k2, int sum1,int sum2,int n){
//         if (i<0 && k1 != k2) return INT_MAX;
//         if(i < 0 && k1 == k2) return abs(sum1-sum2);
//         int mini = INT_MAX;
//         for(int p = i+1;p<n;p++){
//             mini = min(sol1(nums,p,k1+1,k2+1,sum1+nums[i],sum2+nums[p],n),mini);
//         }
//         return abs(sum1-sum2);
//     }
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n = nums.size();
//         return sol1(nums,n-1,0,0,0,0,n);
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution solution;
//     vector<int>nums = {2,-1,0,4,-2,-9};
//     cout<<solution.minimumDifference(nums)<<endl;
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> memo;

    int solve(vector<int>& nums, int i, int taken, int sum, int total, int n) {
        if (taken > n / 2) return INT_MAX;
        if (i == n) {
            if (taken == n / 2) {
                int other_sum = total - sum;
                return abs(sum - other_sum);
            }
            return INT_MAX;
        }

        string key = to_string(i) + "|" + to_string(taken) + "|" + to_string(sum);
        if (memo.count(key)) return memo[key];

        int include = solve(nums, i + 1, taken + 1, sum + nums[i], total, n);
        int exclude = solve(nums, i + 1, taken, sum, total, n);

        return memo[key] = min(include, exclude);
    }

public:
    int minimumDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        return solve(nums, 0, 0, 0, total, n);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int> nums = {2, -1, 0, 4, -2, -9};
    cout << solution.minimumDifference(nums) << endl;
    return 0;
}
