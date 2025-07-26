#include<bits/stdc++.h>
using namespace std;
int shortest_dist(vector<vector<int>>&matrix,int i, int j,int n ,int m){
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    q.push({{i,j},0});
    visited[i][j] = 1;
    vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        int currx = q.front().first.first;
        int curry = q.front().first.second;
        int currdist = q.front().second;
        q.pop();
        if (matrix[currx][curry] == 1 ) return currdist;
        for(int k = 0;k < 4;k++){
            int newx = currx + directions[k][0];
            int newy = curry + directions[k][1];
            if (newx > -1 && newy > -1 && newx < n && newy < m && visited[newx][newy] == 0){
                q.push({{newx,newy},currdist + 1});
                visited[newx][newy] = 1;
            }
        }
    }
    return -1;
}
vector<vector<int>>matrix01(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>result(n,vector<int>(m));
    for(int i = 0 ; i< n ; i ++){
        for(int j = 0 ; j < m ; j++){
            result[i][j] = shortest_dist(matrix,i,j,n,m);
        }
    }
    return result;
}
int main(){
    int n ,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    int num;
    for (int i = 0;i<m;i++){
        for(int j = 0 ;j<m ;j++){
            cin>>num;
            matrix[i][j] = num;
        }
    }
    vector<vector<int>>result = matrix01(matrix);
    for(auto it: result){
        for(auto itt : it) cout<<itt<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}