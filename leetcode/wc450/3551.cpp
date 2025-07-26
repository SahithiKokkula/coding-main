#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sum_digi(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num /=10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>arr;
        int n = 0;
        for(int it : nums){
            arr.push_back({sum_digi(it),it});
            n++;
        }
        sort(arr.begin(),arr.end());
        int swaps = 0;
        vector<bool> visited(n, false);
        unordered_map<int,int>val_idx;
        for(int i = 0 ;i < n ; i++){
            val_idx[arr[i].second] = i;
        }
        for(int i = 0 ; i < n ; i++){
            if( visited[i] || val_idx[nums[i]] == i) continue;
            
            else{
                
            }
        }
        return swaps;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {18,43,34,16};
    cout<<solution.minSwaps(nums)<<endl;
    return 0;
}