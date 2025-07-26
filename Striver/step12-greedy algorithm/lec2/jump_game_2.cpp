#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        while(r<=n-1){
            int farthest = 0;
            for(int i = l; i<r;i++){
                farthest = max(l + nums[i],farthest);
            }
            l = r+1;
            jumps++;
            r = farthest;
        }
        return jumps;
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
    int result = solution.jump(nums);
    cout<<result;
    return 0;
}