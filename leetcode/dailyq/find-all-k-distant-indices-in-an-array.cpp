#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = 0;
        vector<int>key_ele;
        for(int it: nums){
            if(it == key){
                key_ele.push_back(n);
            }
            n++;
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            for(int it : key_ele){
                if(abs(i-it) <= k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {3,4,9,1,3,9,5};
    int key = 9;
    int k = 1;
    vector<int>ans = solution.findKDistantIndices(nums,key,k);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}