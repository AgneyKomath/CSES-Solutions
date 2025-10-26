#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> dist(n, 1000000);
    queue<int> que;
    for(int i = 0; i < n; i++){
        int v;
        cin>>v;
        if(v == 1){
            dist[i] = 0;
            que.push(i);
        }
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int v : adj[u]){
            if(dist[v] <= dist[u] + 1) continue;
            dist[v] = dist[u] + 1;
            que.push(v);
        }
    }
    
    int log = __lg(n) + 1;
    vector<vector<int>> jump(log, vector<int>(n, -1));  
    vector<vector<int>> mn(log, vector<int>(n, 2000000));  
    vector<int> depth(n);
    
    auto dfs = [&](int u, auto &&dfs)->void{
        for(int v : adj[u]){
            if(v != jump[0][u]){
                jump[0][v] = u;
                depth[v] = depth[u] + 1;
                mn[0][v] = min(dist[v], dist[u]);
                dfs(v, dfs);
            }
        }
    };
    depth[0] = 0;
    mn[0][0] = dist[0];
    dfs(0, dfs);

    for(int i = 1; i < log; i++){
        for(int u = 0; u < n; u++){
            int v = jump[i - 1][u];
            if(v == -1) continue;
            jump[i][u] = jump[i - 1][v];
            mn[i][u] = min(mn[i - 1][u], mn[i - 1][v]);
        }
    }

    auto kth_ancestor = [&](int u, int k)->pair<int, int>{
        int mnv = dist[u];
        for(int i = 0; i < log && u != -1; i++){
            if((k >> i) & 1){
                mnv = min(mnv, mn[i][u]);
                u = jump[i][u];
            }
        }
        return {u, mnv};
    };

    auto lca = [&](int u, int v)->pair<int, int>{
        if(depth[u] < depth[v]) swap(u, v);
        auto [ku, mnv] = kth_ancestor(u, depth[u] - depth[v]);
        u = ku;
        if(u == v) return {u, mnv};
        int res = min({mnv, dist[u], dist[v]});
        for(int i = log - 1; i >= 0; i--){
            if(jump[i][u] != jump[i][v]){
                res = min({res, mn[i][u], mn[i][v]});
                u = jump[i][u];
                v = jump[i][v];
            }
        }
        return {jump[0][u], min(res, mn[0][u])};
    };

    while(q--){
        int u, v;
        cin>>u>>v;
        u--, v--;

        auto [l, mnd] = lca(u, v);
        int baseDist = depth[u] + depth[v] - 2 * depth[l];

        cout<<baseDist + 2 * mnd<<'\n';
    }

    return 0;
}
