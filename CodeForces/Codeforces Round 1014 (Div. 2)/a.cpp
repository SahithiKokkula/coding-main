#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int num;
        for(int i = 0;i <n ;i++){
            cin>>num;
            mini = min(num,mini);
            maxi = max(num, maxi);
        }
        cout<<maxi - mini<<endl;
    }
}