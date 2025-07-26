#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int bits_flipped = 0;
        queue<int>q;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int max_len = 0;
        while(i <= j && j < n){
            if(nums[j] != 1){
                if(bits_flipped < k){
                    bits_flipped++;
                    q.push(j-1);
                }
                else{
                    i = q.front() + 1;
                    q.pop();
                    q.push(j);
                }
            }
            max_len = max(max_len, j - i);
            j++;
        }
        return max_len;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums ={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout<<solution.longestOnes(nums,k);
    return 0;
}