#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        int maxi = -1;

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (x[i] == x[j]) continue;

                unordered_set<int> seen = {x[i], x[j]};  // keep track of used x values
                for (int k = j + 1; k < n; ++k) {
                    if (seen.count(x[k])) continue;
                    maxi = max(maxi, y[i] + y[j] + y[k]);
                }
            }
        }

        return maxi;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>x = {1,2,1,3,2};
    vector<int> y ={5,3,4,6,2};
    cout<<solution.maxSumDistinctTriplet(x,y);
    return 0;
}