// // #include<bits/stdc++.h>
// // using namespace std;
// // class Solution{
// // private:
// //     long long dfs(vector<vector<pair<int,long long>>>&adj_list,pair<int,int>&maximini,pair<int,int> node){
// //         if (node.first == 1){
// //             return maximini.first + maximini.second;
// //         }
// //         maximini.first = max(maximini.first,node.second);
// //         maximini.second = min(maximini.second,node.second);
// //         long long mini  = INT64_MAX;
// //         for(auto it :adj_list[node.first]){
// //             mini = (long long) min((long long)mini,(long long)dfs(adj_list,maximini,it));
// //         }
// //         return mini;
// //     }
// // public:
// //     void solve(){
// //         int n,m;
// //         cin>>n>>m;
// //         vector<vector<pair<int,long long>>>adj_list(n+1);
// //         int u,v;
// //         long long w;
// //         for(int i = 0 ; i < m ; i++){
// //             cin>>u>>v>>w;
// //             adj_list[u].push_back({v,w});
// //             adj_list[v].push_back({u,w});
// //         }
// //         pair<int,int>maximini = {INT64_MIN,INT64_MAX};
// //         cout<<dfs(adj_list,maximini,{n,0})<<endl;
// //     }
// // };

// // int main(){
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(nullptr);
// //     Solution solution;
// //     int t;
// //     cin>>t;
// //     while(t--){
// //         solution.solve();
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// private:
//     long long dfs(int curr, int dest, vector<vector<pair<int, long long>>>& adj,
//                   vector<bool>& visited, long long cur_max, long long cur_min) {
//         if (curr == dest) return cur_max + cur_min;

//         visited[curr] = true;
//         long long res = LLONG_MAX;

//         for (auto it: adj[curr]) {
//             if (!visited[it.first]) {
//                 long long new_max = max(cur_max, it.second);
//                 long long new_min = min(cur_min, it.second);
//                 res = min(res, dfs(it.first, dest, adj, visited, new_max, new_min));
//             }
//         }

//         visited[curr] = false;
//         return res;
//     }

// public:
//     void solve() {
//         int n, m;
//         cin >> n >> m;

//         vector<vector<pair<int, long long>>> adj(n + 1);
//         for (int i = 0; i < m; i++) {
//             int u, v;
//             long long w;
//             cin >> u >> v >> w;
//             adj[u].emplace_back(v, w);
//             adj[v].emplace_back(u, w);
//         }

//         vector<bool> visited(n + 1, false);
//         long long result = dfs(n, 1, adj, visited, LLONG_MIN, LLONG_MAX);
//         cout << result << endl;
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution solution;
//     int t;
//     cin >> t;
//     while (t--) {
//         solution.solve();
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;

struct dsu_disjointset {
    vector<int> parent, size;
    vector<long long> minWeight;

    dsu_disjointset(int n) : parent(n + 1), size(n + 1, 1), minWeight(n + 1, INF) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        return parent[v] == v ? v : parent[v] = find(parent[v]);
    }

    void unite(int a, int b, long long weight) {
        a = find(a);
        b = find(b);
        if (a == b) {
            minWeight[a] = min(minWeight[a], weight);
            return;
        }
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        minWeight[a] = min({minWeight[a], minWeight[b], weight});
    }
};

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges(m);
        for (auto& edge : edges)
            cin >> edge.u >> edge.v >> edge.w;

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });

        dsu_disjointset dsu(n);
        long long answer = INF;

        for (const auto& edge : edges) {
            dsu.unite(edge.u, edge.v, edge.w);
            if (dsu.find(1) == dsu.find(n)) {
                long long totalCost = edge.w + dsu.minWeight[dsu.find(1)];
                answer = min(answer, totalCost);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
