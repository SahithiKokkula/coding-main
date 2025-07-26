#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map <int,int> mapp;
        vector<int>arr;
        int num;
        for(int i = 0;i < n; i++){
            cin>>num;
            arr.emplace_back(num);
            mapp[num]++;
        }
        int r=0;
        int ansl = -1 , ansr = -1;
        int len = 0;
        for (int i = 0; i < n; i++){
            r = max(i,r);
            while( r < n && mapp[arr[r]] == 1){
                r++;
            }
            if (r-i > len){
                len = r-i;
                ansl = i;
                ansr = r-1;
            }
        }
        if (ansl == -1){
            cout<<0<<endl;
        }
        else{
            cout<<ansl+1<<" "<<ansr + 1<<endl;
        }
    }
    return 0;
}