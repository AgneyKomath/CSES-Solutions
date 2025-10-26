#include <bits/stdc++.h>
using namespace std;

// Easy Solution
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        cout<<min(u, v)<<' '<<max(u, v)<<'\n';
    }

    return 0;
}

// // Complex Solution
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m;
//     cin>>n>>m;

//     vector<multiset<int>> adj(n);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin>>u>>v;
//         u--, v--;
//         adj[u].insert(v);
//         adj[v].insert(u);
//     }

//     vector<pair<int, int>> res;

//     vector<int> vis(n, 0);

//     auto dfs = [&](int u, auto &&dfs)->void{
//         vis[u] = 1;
//         while(!adj[u].empty()){
//             int v = *adj[u].begin();
//             if(vis[v] == 0){
//                 res.emplace_back(u, v);
//                 adj[u].erase(adj[u].find(v));
//                 adj[v].erase(adj[v].find(u));
//                 dfs(v, dfs);
//             }
//             else if(vis[v] == 1){
//                 res.emplace_back(v, u);
//                 adj[u].erase(adj[u].find(v));
//                 adj[v].erase(adj[v].find(u));
//             }
//         }
//         vis[u] = 2;
//     };

//     for(int i = 0; i < n; i++){
//         if(vis[i]) continue;
//         dfs(i, dfs);
//     }

//     for(auto [u, v] : res) cout<<u + 1<<' '<<v + 1<<'\n';

//     return 0;
// }
