#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int w,h,a,b;
        cin>>w>>h>>a>>b;
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int diff1 = abs(x1-x2);
        int diff2 = abs(y1-y2);
        if(diff1 != 0 && (diff1 % a) == 0){
            cout<<"yes"<<endl;
            return;
        }
        if(diff2 != 0 && (diff2 % b) == 0){
            cout<<"yes"<<endl;
            return;
        }
        cout<<"No"<<endl;
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        solution.solve();
    }
    return 0;
}