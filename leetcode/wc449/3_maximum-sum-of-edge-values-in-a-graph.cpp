#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        if(n==1){
            return 1;
        }else if(n==2){
            return 1*2;
        }
        int m = edges.size();
        bool cycle = (n == m);
        long long ans = 0;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }

        ans += (nums[n - 1] * nums[n - 2]);
        ans += (nums[n - 1] * nums[n - 3]);
        int i = n - 2;
        while (i >= 0 && i - 2 >= 0) {
            ans += (nums[i] * nums[i - 2]);
            i -= 2;
        }
        i = n - 3;
        while (i >= 0 && i - 2 >= 0) {
            ans += (nums[i] * nums[i - 2]);
            i -= 2;
        }
        if(cycle){
            ans+=(nums[0]*nums[1]);
        }
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>edges = {{0,3},{4,5},{2,0},{1,3},{2,4},{1,5}};
    int n = 6;
    cout<<solution.maxScore(n,edges);
    return 0;
}