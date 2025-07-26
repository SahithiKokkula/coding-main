#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    vector<vector<int>> convert_edges(vector<vector<int>>&edges, int n){
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for(int i = 0; i< n; i++){
            mat[i][i] = 0;
        }
        return mat;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat = convert_edges(edges,n);

        for(int via = 0 ; via < n; via++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j< n;j++){
                    mat[i][j] = min(mat[i][via]+mat[via][j],mat[i][j]);
                }
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

        int city_connected = n;
        int city_no = -1;
        for(int i = 0 ; i < n ; i++){
            int city = 0;
            for(int j = 1; j < n ; j++){
                if (mat[i][j] <= distanceThreshold){
                    city++;
                }
            }
            if(city < city_connected){
                city_connected = city;
                city_no  = i ;
            } 
            else if (city == city_connected && i>city_no){
                city_no  = i;
            }
        }
        return city_no;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>>edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int distanceThreshold = 2;
    int n = 5;
    Solution solution;
    int result = solution.findTheCity(n,edges,distanceThreshold);
    cout<<result<<endl;
    return 0;
}
