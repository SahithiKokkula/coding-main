#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
bool case1(vector<vector<int>>& matrix , int i,int j){
    for( j ; j>=0;j--){
        if (matrix[i][j] == 0) return true; 
    }
    return false;
}
bool case2(vector<vector<int>>& matrix , int i, int j){
    for( i ; i>=0;i--){
        if (matrix[i][j] == 0) return true; 
    }
    return false;
}
public:
    bool checkMatrix(vector<vector<int>>& matrix, int n, int m) {
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 1) {
                    bool check = case1(matrix,i,j) && case2(matrix,i,j);
                    if (check) return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        string str;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = (str[j] == '1') ? 1 : 0;
            }
        }
        Solution solution;
        cout << (solution.checkMatrix(matrix, n, m) ? "YES" : "NO") << endl;
    }
    return 0;
}