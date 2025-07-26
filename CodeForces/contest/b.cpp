#include<bits/stdc++.h>
using namespace std;
class Solution{

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num;
        int ref;
        int cnt1 = 0; //pos
        int cnt2 = 0; //neg
        for(int i = 0 ; i<n ;i++){
            cin>>num;
            if(i==0) ref = abs(num);
            else{
                if(num ){
                    cnt2++;
                }
                if(abs(num) < ref){
                    cnt1++;
                }
            }
        }
        int req;
        if(n%2==0){
            req = n/2-1;
            
        }
        else{
            req = n/2;

        }
        if(cnt1 != req && cnt2 != req){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
