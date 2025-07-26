#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int req_k(vector<int>&arr, long time){
        int k = 1;
        long prevsum = 0;
        for(int it:arr){
            prevsum += (long) it;
            if (prevsum > time){
                k++;
                prevsum = (long) it;
            }
        }
        return k;
    }
public:
    int minTime(vector<int>& arr, int k) {
        long low = INT_MIN;
        long high = (long)0;
        for(auto it :arr){
            low = (max(low,(long)it));
            high += (long)it;
        }
        long ans = high;
        while (low <= high){
            long mid = (high - low)/2 + low;
            int rk = req_k(arr,mid);
            if (rk>k){
                low = mid + 1;
            }
            else if (rk < k){
                high = mid - 1;

            }
            else{
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>arr = {5, 10, 30, 20, 15};
    int k = 3;
    cout<<solution.minTime(arr,k);
    return 0;
}