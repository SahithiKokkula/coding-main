#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
bool hasDuplicate(const vector<int>& arr) {
    set<int> seen;
    for (int num : arr) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}
    int uniqueXorTriplets(vector<int>& nums) {
        if(hasDuplicate(nums)){
            int n = nums.size();
        if (n==1) return 2;
        if (ceil(log2f(n)) == floor(log2f(n))) n++;
        return pow(2,(ceil(log2f(n))));
        }
        int n = nums.size();
        if (n==1) return 1;
        if(n==2 )return 2;
        if (ceil(log2f(n)) == floor(log2f(n))) n++;
        return pow(2,(ceil(log2f(n))));
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {6,7,8,9};
    cout<<endl<<solution.uniqueXorTriplets(nums);
    return 0;

    // for(int i = 0 ;i<=8;i++){
    //     for(int j = 0;j<=8;j++){
    //         for(int k = 0;k<=8;k++){
    //             cout<<(i^j^k)<<endl;
    //         }
    //     }
    // }
}