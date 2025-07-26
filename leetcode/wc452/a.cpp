#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long long copy = target;
        long long product = 1;

        for(int it:nums){
            product *= it;
            if(copy != 1 && product>copy){
                long long n = product/copy;
                if (copy*n == product){
                    product = product/n;
                    copy = copy/n;
                }
            }

        }
        return product == target;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {87,91,55,29,49,92,13,90,31,88,74};
    long long target = 299821430594825;
    cout<<solution.checkEqualPartitions(nums,target);
    return 0;
}