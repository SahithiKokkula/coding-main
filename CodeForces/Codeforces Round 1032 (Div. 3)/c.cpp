#include<bits/stdc++.h>
using namespace std;
class Solution{
private:

bool isValidCenter(int row, int col, const vector<pair<int, int>>& points) {
    for (auto& it : points) {
        if (it.first != row && it.second != col)
            return false;
    }
    return true;
}

bool canFormCross(const vector<pair<int, int>>& points) {
    int n = points.size();

    // Try each point as a candidate row or column for the center
    for (int i = 0; i < n; ++i) {
        int r1 = points[i].first;
        int c1 = points[i].second;

        // Fix row, try with column from any point
        for (int j = 0; j < n; ++j) {
            int cj = points[j].second;
            if (isValidCenter(r1, cj, points))
                return true;
        }

        // Fix column, try with row from any point
        for (int j = 0; j < n; ++j) {
            int ri = points[j].first;
            if (isValidCenter(ri, c1, points))
                return true;
        }
    }

    return false;
}
 
public:
    void solve(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>arr(n,vector<int>(m));
        vector<pair<int,int>>maxiloc;
        int num;
        int maxi = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j < m ; j++){
                cin>>num;
                if (num > maxi) {
                    maxi = num;
                    maxiloc.clear();
                    maxiloc.push_back({i, j});
                } else if (num == maxi) {
                    maxiloc.push_back({i, j});
                }
            }
        }
        int a = maxiloc.size();
        if (a <=2){
            cout<<maxi-1<<endl;
            return;
        }
        if(a>m+n-1){
            cout<<maxi<<endl;
            return;
        }
        if(canFormCross(maxiloc)){
            cout<<maxi-1<<endl;
            return;
        }
        cout<<maxi<<endl;
    
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