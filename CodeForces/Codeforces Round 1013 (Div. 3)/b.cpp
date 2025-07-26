#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n ,x;
        cin>>n>>x;
        vector<int>arr(n);
        for(int i = 0; i<n ;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int i = n-1;
        int count= 0;
        int max_possible = 0;
        while(i >= 0){
            count ++;
            if (arr[i] * count >= x){
                max_possible++;
                count  = 0;
            }
            i--;
        }
        cout<<max_possible<<endl;
    }
}