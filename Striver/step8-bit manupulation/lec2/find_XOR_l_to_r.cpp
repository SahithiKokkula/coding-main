#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    // 1 to n
    int XOR_range(int n){
        if (n%4 == 1) return 1;
        if (n%4 == 2) return n+1;
        if (n%4 == 3) return 0;
        if (n%4 == 0) return n;
        return 0;
    }
public:
    int XOR_L_to_R(int l,int r){
        return XOR_range(l-1)^XOR_range(r);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int l,r;
    cin>>l>>r;
    cout<<solution.XOR_L_to_R(l,r);
    return 0;
}