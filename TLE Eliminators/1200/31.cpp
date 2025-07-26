#include<bits/stdc++.h>
using namespace std;
long long nC2(long long n) {
    if (n < 2) return 0;
    return n * (n - 1) / 2;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        long n;
        long num;
        cin>>n;
        vector<long>arr(64,0);
        for(int i=0;i<n;i++){
            cin>>num;
            int pos = 0;
            while (num >>= 1) {
                pos++;
            }
            arr[pos]++;
        }
        unsigned long long ans = 0;
        for(int i = 0;i<64;i++){
            if(arr[i]>=2){
                ans+=nC2(arr[i]);
            }
        }
        cout<<ans<<endl;
    }
    
}