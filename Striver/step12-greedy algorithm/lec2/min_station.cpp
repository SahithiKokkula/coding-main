#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int min_stations(vector<int>&arr , vector<int>&dep){
        int n = arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 0 ,j = 0;
        int cnt = 0;
        int maxcnt = 0;
        while(i<n && j<n){
            if (arr[i] < dep[j]){
                cnt++;
                i++;
                maxcnt = max(cnt,maxcnt);
            }
            else if (arr[i]>arr[j]){
                cnt--;
                j++;
            }
        }
        return maxcnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int>dep = {920, 1200, 1130, 1150, 1900, 2000};
    cout<<solution.min_stations(arr,dep);
    return 0;
}