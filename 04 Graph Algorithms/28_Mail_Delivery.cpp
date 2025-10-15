#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    // Euler Circuit. Graph Should be Connected. Each node must have even degree    
    for(int i = 0; i<n; i++){
        if(adj[i].size() & 1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    // Hierholzer's algorithm
    vector<int> path;
    vector<int> vis(m, 0);
    auto dfs = [&](int u, auto &&dfs)->void{
        while(!adj[u].empty()){
            auto [v, id] = adj[u].back();
            adj[u].pop_back();
            if(vis[id]) continue;
            vis[id] = 1;
            dfs(v, dfs);
        }
        path.push_back(u);
    };

    dfs(0, dfs);
    if(path.size() != m + 1) cout<<"IMPOSSIBLE";
    else{
        for(int u : path) cout<<u + 1<<' ';
    }


    return 0;
}
