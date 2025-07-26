#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        int i = 0 ;
        while(s[i] != '\0'){
            freq[s[i] - 'a']++;
            i++;
        }
        int even_min = INT_MAX;
        int even_max = INT_MIN;
        int odd_min = INT_MAX;
        int odd_max = INT_MIN;
        for(int i = 0; i < 26 ; i++){
            if((freq[i] & 1) == 1){
                odd_max = max(odd_max,freq[i]);
                odd_min = min(odd_min,freq[i]);
            }
            else{
                even_max = max(even_max,freq[i]);
                even_min = min(even_min,freq[i]);
            }
        }
        return odd_max - even_min;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "aaaaabbc";
    cout<<solution.maxDifference(s);
    return 0;
}