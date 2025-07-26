#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long long num) {
    if (num < 0) {
        return false; // Negative numbers cannot be perfect squares
    }
    long long sqrtNum = static_cast<long long>(std::sqrt(num));
    return (sqrtNum * sqrtNum == num);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr ={3 ,2 ,1};
        long long sum = 0;
        long long total_sum = n*(n-1)/2;
        long long sqrtnum = sqrtf(total_sum);
        if (n==1 || sqrtnum* sqrtnum == total_sum){
            cout<<-1<<endl;
        }else if (n==2){
            cout<<2<<" "<<1<<endl;
        }
        else if(n==3) {
            cout<<3<<" "<<2<<" "<<1<<endl;
        }
        else{
            for(int i=n;i>3;i--){
                arr.emplace_back(i);
            }
            long long sum = 5;
            for(int i = 2;i<n;i++){
                sum += arr[i];
                if (isPerfectSquare(sum) && i+1<n){
                    sum = sum - arr[i] + arr[i+1];
                    swap(arr[i],arr[i+1]);
                }
            }
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
}