#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int getCost(vector<int>& heights, vector<int>& cost, int mid,int n){
        int c = 0;
        for(int i = 0 ; i < n ; i++){
            c += abs(heights[i] - mid) * cost[i];
        }
        return c;
    }
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int lo = heights[0],hi = heights[0];
        int n = heights.size();
        for(int i = 0 ; i < n ; i++){
            lo = min(lo,heights[i]);
            hi = max(hi,heights[i]);
        }
        int ans = INT_MAX;
        while(lo <= hi){
            int mid1 = (hi - lo) / 3 + lo;
            int mid2 = hi - (hi - lo) / 3;
            int c1 = getCost(heights,cost,mid1,n);
            int c2 = getCost(heights,cost,mid2,n);
            ans = min(ans , min(c1 , c2));
            if(c1 > c2){
                lo = mid1 + 1;
            }
            else{
                hi = mid2 - 1;
            }
        }
        return ans;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>heights = {1,2,3};
    vector<int>cost = {10,100,1000};
    cout<<solution.minCost(heights,cost);
    return 0;
}