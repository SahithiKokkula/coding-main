#include<bits/stdc++.h>
using namespace std;
int check(vector<int>& arr, int k, int n) {
    int low = 0, high = n - 1, num = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - 1 - mid; 

        if (missing >= k) {
            num = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return num;
}

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();

    if (arr[0] - 1 >= k) {
        return k;
    }

    int num = check(arr, k, n);

    if (num == -1) {
        return k + n;
    }

    int missingUntilPrev = (num > 0) ? (arr[num - 1] - 1 - (num - 1)) : 0;

    int remaining = k - missingUntilPrev;

    return arr[num - 1] + remaining;
}

int main(){
    // int k;
    // cin>>k;
    // int n;
    // cin>>n;
    vector <int> arr ={2};
    // for(int i=0;i<n;i++){
    //     int num;
    //     cin>>num;
    //     arr.emplace_back(num);
    // }
    cout<<findKthPositive(arr,1);
    return 0;
}