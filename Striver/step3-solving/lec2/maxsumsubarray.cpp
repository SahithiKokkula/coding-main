#include<bits/stdc++.h>
using namespace std;
// Kadane's Algorithm
long long maxSubarraySum(vector<int> arr, int n){   
    if (n==0) return 0;
    // Write your code here.
    long long maxsum = INT64_MIN;
    long long sum=0;
    for (int i=0;i<n;i++){
        if (sum<0){
            sum=0;
        }
        sum +=arr[i];
        if (sum>maxsum){
            maxsum=sum;
        }
    }
    if (maxsum<0) return 0;
    return maxsum;
}
int main(){
    vector<int>a;
    int n;
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        a.emplace_back(num);
    }
    cout<<maxSubarraySum(a,n);
}