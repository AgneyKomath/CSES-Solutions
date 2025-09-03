#include <bits/stdc++.h>
using namespace std;

vector<bool> check(int u, vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> vis(n, 0);
    auto dfs = [&](int node, auto &&dfs){
        if(vis[node]) return;
        vis[node] = 1;
        for(auto v:adj[node]) dfs(v, dfs);
    };
    dfs(u, dfs);
    return vis;
}

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<array<int, 3>> edges(m);

    vector<vector<int>> adj(n), revadj(n);
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back(v);
        revadj[v].push_back(u);
        edges[i] = {u, v, -w};
    }

    auto vis = check(0, adj), vis2 = check(n-1, revadj);

    for(int i = 0; i<n; i++) vis[i] = vis[i] & vis2[i];
    
    vector<long long> dist(n, INF);
    dist[0] = 0;

    for(int i = 0; i<n; i++){
        for(auto [u, v, w]:edges){
            if(!vis[v] || !vis[u]) continue;
            if(dist[u] != INF && dist[u] + w < dist[v]){
                if(i==n-1){
                    cout<<"-1";
                    return 0;
                }
                dist[v] = dist[u] + w;
            }
        }
    }

    cout<<-dist[n-1];
    
    return 0;
}
