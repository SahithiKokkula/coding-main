#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements not in the sliding window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // Add the maximum for the current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = solution.maxSlidingWindow(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
