#include<bits/stdc++.h>
using namespace std;
class Solution{

public:
    void solve(){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        bool check = false;

        if (x1 > y1) x1 , y1 ,x2, y2 = y1 , x1 , y2 , x2;
        
        cout<<((x1 < y1  && x2>y2)?"No":"Yes");
        cout<<endl;
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