#include <bits/stdc++.h>
using namespace std;

struct Tree{
    // Tree Struct by Fusion15
    int root, log, n, timer;
    vector<vector<int>> adj, jump;
    vector<int> depth, par, sub, tin, tout;

    Tree(vector<vector<int>> & a, int r = 0){
        adj = a, root = r;
        init();
    }

    Tree(vector<int> &p){
        int r = -1, n = p.size();
        adj.resize(n);
        for(int i = 0; i < n; i++){
            if(p[i] != -1){
                adj[i].push_back(p[i]);
                adj[p[i]].push_back(i);
            }
            else{
                r = i;
            }
        }
        root = r;
        init();
    }

    void init(){
        n = adj.size();
        log = __lg(n) + 1;
        timer = 0;
        
        jump.assign(log, vector<int>(n, -1));
        par.assign(n, -1);
        depth.assign(n, 0);
        sub.assign(n, 1);
        tin.assign(n, 0);
        tout.assign(n, 0);
        
        dfs(root);
        build();
    }

    void dfs(int u){
        tin[u] = timer++;
        for(int v : adj[u]){
            if(v == par[u]) continue;
            par[v] = u;
            depth[v] = 1 + depth[u];
            dfs(v);
            sub[u] += sub[v];
        }
        tout[u] = timer - 1;
    }

    void build(){
        for(int i = 0; i < n; i++) jump[0][i] = par[i];
        for(int i = 1; i < log; i++){
            for(int j = 0; j < n; j++){
                if(jump[i - 1][j] == -1) continue;
                jump[i][j] = jump[i - 1][jump[i - 1][j]];
            }
        }
    }

    int kth_ancestor(int u, int k){
        if(k > depth[u]) return -1;  
        for(int i = 0; i < log; i++){
            if((k >> i) & 1){
                u = jump[i][u];
            }
        }
        return u;
    }

    int lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        u = kth_ancestor(u, depth[u] - depth[v]);
        if(u == v) return u;
        for(int i = log - 1; i >= 0; i--){
            if(jump[i][u] != jump[i][v]){
                u = jump[i][u];
                v = jump[i][v];
            }
        }
        return jump[0][u];
    }

    int distance(int u, int v){
        int ancestor = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[ancestor];
    }

    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tree tr(adj);

    while(q--){
        int u, v;
        cin>>u>>v;
        u--, v--;
        int res = tr.distance(u, v);
        cout<<res<<'\n';
    }

    return 0;
}
