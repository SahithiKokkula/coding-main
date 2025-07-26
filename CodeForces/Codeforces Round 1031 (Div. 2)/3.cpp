// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// private:
//     int move_window_right(vector<vector<char>>&mine,int n,int m,int i,int j,int k,int win_g){
//         int size = 2 * k + 1;
//         int top = i - k;
//         int bottom = i + k;
//         int left = j - k;
//         int right = j + k;

//         vector<pair<int,int>> edge;

        

//         // Right edge (top to bottom)
//         for (int row = top + 1; row <= bottom - 1; row++) {
//             int x = row;
//             int y = right;
//             if (x >= 0 && x < n && y >= 0 && y < m){
//                 if(mine[x][y] == 'g') win_g++;
//             }
//         }

//         // Left edge (bottom to top)
//         for (int row = bottom - 1; row >= top + 1; row--) {
//             int x = row;
//             int y = left - 1;
//             if (x >= 0 && x < n && y >= 0 && y < m){
//                 if(mine[x][y] == 'g') win_g--;
//             }
//         }

//         return win_g;
//     }
// private:
//     int move_window_down(vector<vector<char>>&mine,int n,int m,int i,int k,int win_g){
//         int size = 2 * k + 1;
//         int j = 0;
//         int top = i - k;
//         int bottom = i + k;
//         int left = j - k;
//         int right = j + k;

//         vector<pair<int,int>> edge;

//         // Top edge (left to right)
//         for (int col = left - 1; col <= right; col++) {
//             int x = top;
//             int y = col;
//             if (x >= 0 && x < n && y >= 0 && y < m){
//                 if(mine[x][y] == 'g') win_g--;
//             }
//         }

        

//         // Bottom edge (right to left)
//         for (int col = right; col >= left; col--) {
//             int x = bottom;
//             int y = col;
//             if (x >= 0 && x < n && y >= 0 && y < m){
//                 if(mine[x][y] == 'g') win_g++;
//             }
//         }

//         return win_g;
//     }
// public:
//     void solve(){
//         int n,m,k;
//         cin>>n>>m>>k;
//         int total_g = 0;
//         bool empty_present = false;
//         char c;

//         vector<vector<char>>mine(n,vector<char>(m,'.'));
//         for(int i = 0 ; i < n ; i++){
//             for(int j = 0 ; j < m ; j++){
//                 cin>>c;
//                 mine[i][j] = c;
//                 if(c == 'g') total_g++;
//                 if(c == '.') empty_present = true;
//             }
//         }
//         if(!empty_present){
//             cout<<0<<endl;
//             return;
//         }
//         int window_g = 0;
//         for(int i = 0 ; i < k ; i++){
//             for(int j = 0 ; j < k ; j++){
//                 if(mine[i][j] == 'g'){
//                     window_g++;
//                 }
//             }
//         }
//         int ans = 0;
//         for(int i = 0 ; i < n ; i++){
//             int win_row_start = window_g;
//             if(mine[i][0] == '.'){
//                 ans = max(ans,total_g - window_g);
//             }
//             for(int j = 1; j < m;j++){
//                 int window_shit_right = move_window_right(mine,n,m,i,j,k,win_row_start);
//                 if(mine[i][j] == '.'){
//                     ans = max(ans,total_g - window_shit_right);
//                 }
//             }
//             if(i+1<n){
//                 window_g = move_window_down(mine,n,m,i + 1,k,win_row_start);
//             }
//         }
//         cout<<ans<<endl;
//         return;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution solution;
//     int t;
//     cin>>t;
//     while(t--){
//         solution.solve();
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
//     void solve(){
//         int n, m, k;
//         cin >> n >> m >> k;
//         vector<string> g(n);
//         for (auto& s : g) cin >> s;
//         vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
//         int total_g = 0;
//         for (int i = 0; i < n; ++i)
//             for (int j = 0; j < m; ++j) {
//                 int add = (g[i][j] == 'g');
//                 total_g += add;
//                 arr[i + 1][j + 1] =
//                     arr[i + 1][j] + arr[i][j + 1] - arr[i][j] + add;
//             }

//         auto gold_2 = [&](int x1, int y1, int x2, int y2) -> int {
//             if (x1 > x2 || y1 > y2) return 0;
//             return arr[x2 + 1][y2 + 1] - arr[x1][y2 + 1]
//                  - arr[x2 + 1][y1]   + arr[x1][y1];
//         };

//         int gold_1 = INT_MAX;
//         int inside_block = k - 1;

//         for (int x = 0; x < n; ++x)
//             for (int y = 0; y < m; ++y)
//                 if (g[x][y] == '.') {
//                     int x1 = max(0, x - inside_block);
//                     int y1 = max(0, y - inside_block);
//                     int x2 = min(n - 1, x + inside_block);
//                     int y2 = min(m - 1, y + inside_block);
//                     int loss = gold_2(x1, y1, x2, y2);
//                     gold_1 = min(gold_1, loss);
//                 }
//         cout << total_g - gold_1 << '\n';
//     }
// };



// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution solution;
//     int t;
//     cin >> t;
//     while (t--) {
//         solution.solve();
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

class Finder {
public:
    void process() {
        int rows, cols, blockSize;
        cin >> rows >> cols >> blockSize;
        vector<string> grid(rows);
        for (auto& row : grid) cin >> row;
        
        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));
        int totalGold = 0;
        
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                int isGold = (grid[i][j] == 'g');
                totalGold += isGold;
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] 
                                        - prefixSum[i][j] + isGold;
            }

        auto countGoldInArea = [&](int r1, int c1, int r2, int c2) -> int {
            if (r1 > r2 || c1 > c2) return 0;
            return prefixSum[r2 + 1][c2 + 1] - prefixSum[r1][c2 + 1] 
                 - prefixSum[r2 + 1][c1] + prefixSum[r1][c1];
        };

        int minLoss = INT_MAX;
        int offset = blockSize - 1;

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (grid[i][j] == '.') {
                    int r1 = max(0, i - offset);
                    int c1 = max(0, j - offset);
                    int r2 = min(rows - 1, i + offset);
                    int c2 = min(cols - 1, j + offset);
                    int loss = countGoldInArea(r1, c1, r2, c2);
                    minLoss = min(minLoss, loss);
                }
                
        cout << totalGold - minLoss << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Finder solver;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solver.process();
    }
    return 0;
}
