#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int beauty(vector<int>&freq){
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto it : freq){
            if (it > 0) {
                maxi = max(maxi ,it);
                mini = min(mini ,it);
            }
        }
        return maxi - mini;
    }

public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;
                sum += beauty(freq);
            }
        }
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "aabcbaa";
    cout<<solution.beautySum(s)<<endl;
    return 0;
}