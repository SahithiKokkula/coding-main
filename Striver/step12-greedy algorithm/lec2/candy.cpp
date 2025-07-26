#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int candy(vector<int>&rating){
        int n = rating.size();
        vector<int>ncandy(n,1);
        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (rating[i] > rating[i-1]) {
                ncandy[i] = ncandy[i-1] + 1;
            }
        }
        
        // Right to left pass
        for (int i = n-2; i >= 0; i--) {
            if (rating[i] > rating[i+1]) {
                ncandy[i] = max(ncandy[i], ncandy[i+1] + 1);
            }
        }
        
        int total = 0;
        for (int num : ncandy) {
            total += num;
        }
        
        return total;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>rating = {1,2,0,5,7,8,1};
    cout<<solution.candy(rating);
    return 0;
}