#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sum_digi(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num /=10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int i = 0;
        for(int it : nums){
            if(sum_digi(it) == i) return i;
            i++;
        }
        return -1;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {1,10,11};
    cout<<solution.smallestIndex(nums)<<endl;
    return 0;
}