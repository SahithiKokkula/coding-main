#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m = n*(n-1)/2;
        vector<int>b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        if (b[0]==b[m-1]){
            for(int i=0;i<n;i++){
                cout<<b[0]<<" ";
            }
            cout<<endl;
            continue;
        }
        map <int,int> mp;
        for(int i=0;i<m;i++){
            mp[b[i]]++;
        }
        vector<int>a;

        for(auto mpval:mp){
            while(mpval.second >= n-1-a.size()){
                mpval.second -= n-1-a.size();
                a.emplace_back(mpval.first);
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}