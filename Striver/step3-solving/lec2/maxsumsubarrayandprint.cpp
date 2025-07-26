#include<bits/stdc++.h>
using namespace std;
// Kadane's Algorithm
void maxSubarraySum(vector<int> arr, int n){   
    
    // Write your code here.
    long long maxsum = INT64_MIN;
    long long sum=0;
    int low=0;
    int high=0;
    for (int i=0;i<n;i++){
        if (sum<0){
            sum=0;
            low=i;
        }
        sum +=arr[i];
        if (sum>maxsum){
            maxsum=sum;
            high=i;
        }
    }
    if (maxsum<0) {
        low = 0;
        high = 0;
    }
    for (int i=low;i<=high;i++){
        cout<<arr[i]<<" ";
    }
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
    maxSubarraySum(a,n);
}