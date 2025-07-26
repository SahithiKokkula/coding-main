#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    void floydWarshall(vector<vector<int>>&mat,int n) {
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if (mat[i][j] == -1){
                    mat[i][j] = 1e9;
                }
                if(i == j ){
                    mat[i][j] = 0;
                }
            }
        }

        for(int via = 0 ; via < n; via++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j< n;j++){
                    mat[i][j] = min(mat[i][via]+mat[via][j],mat[i][j]);
                }
            }
        }

        // negative cycle detection
        for(int i = 0; i< n;i++){
            if(mat[i][i] < 0) {
                cout<<"NEGATIVE CYCLE";
                return;
            }
        }

        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if (mat[i][j] == 1e9){
                    mat[i][j] = -1;
                }
                if(i == j ){
                    mat[i][j] = 0;
                }
            }
        }
    }
public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        floydWarshall(mat,n);
    }
};

int main(){
    vector<vector<int>> matrix = {{0, 1, 43},{1, 0, 6}, {-1, -1, 0}};
    int V = 6;
    int src = 0;
    Solution solution;
    solution.shortestDistance(matrix);
    for(auto it : matrix){
        for(auto itt : it){
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}