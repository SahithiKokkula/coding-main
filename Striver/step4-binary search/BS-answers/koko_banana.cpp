#include<bits/stdc++.h>
using namespace std;
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (long long  i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}
int minEatingSpeed(vector<int>piles,int h){
    return minimumRateToEatBananas(piles,h);
}

int main(){
    int h;
    cin>>h;
    int n;
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.emplace_back(num);
    }
    cout<<minEatingSpeed(arr,h);
    return 0;
}