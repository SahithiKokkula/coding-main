#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count = 0;
        bool check = false;
        int num;
        vector<int>numc = {3,1,2,1,0,1};
        for(int i = 0; i< n;i++){
            cin>>num;
            if (num <= 5){
                numc[num]--;
            }
            if (check == false && numc[0]<=0 && numc[1]<=0 && numc[2]<=0 && numc[3]<=0 && numc[4]<=0 && numc[5]<=0 ){
                check = true;
                count  = i +1;
            }
        }
        cout<<count<<endl;
    }
}