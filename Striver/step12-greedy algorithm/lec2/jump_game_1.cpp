#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool check_zero(vector<int>&nums,int index,int n,bool lst){
        int zero_idx = index;
        index --;
        while( index >= 0){
            if ((zero_idx - index) == nums[index]){
                if (lst) return true;
                else index--;
            }
            else if ((zero_idx - index) < nums[index]){
                return true;
            }
            else{
                index--;
            }
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return true;
        if (nums[0] == 0 ) return false;
        for(int i = n-1;i>=0;i--){
            if (nums[i] == 0){
                if (!check_zero(nums , i , n, i == (n-1))) return false;
            }
        }
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    bool result = solution.canJump(nums);
    cout<<result;
    return 0;
}