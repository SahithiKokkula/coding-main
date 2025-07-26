#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int it: nums){
            sum+=it;
        }
        int test = floor(sum/k);
        int result = sum - test*k;
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {4,1,3};
    int k = 4;
    cout<<solution.minOperations(nums,k);
    return 0;
}