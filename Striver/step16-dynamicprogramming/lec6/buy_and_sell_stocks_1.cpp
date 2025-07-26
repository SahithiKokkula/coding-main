#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int mini = prices[0];
        for(int i = 1; i < n;i++){
            mini = min(mini,prices[i]);
            profit = max(profit , prices[i] - mini);
        }
        return profit;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>prices= {7,1,5,3,6,4};
    cout<<solution.maxProfit(prices)<<endl;
    return 0;
}