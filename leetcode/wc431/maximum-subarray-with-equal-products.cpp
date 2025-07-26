#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int gcd_f(int a, int b) {
        if (b == 0)
            return a;
        return gcd_f(b, a % b);
    }
public:
    int maxLength(vector<int>& nums) {
        int i = 0 ; 
        int j = 1;
        int n = nums.size();
        int cnt = 1;
        for(int i = 1 ; i < n ; i++){
            int gcd = nums[i];
            int lcm = nums[i];
            int product = nums[i];

            for(int j = i+1; j < n ; j++){
                gcd = gcd_f(gcd,nums[j]);
                product = product * nums[j];
                lcm = product / gcd;

                if(gcd * lcm == product) cnt = max(cnt,j-i+1);
            }
        }
        return cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}