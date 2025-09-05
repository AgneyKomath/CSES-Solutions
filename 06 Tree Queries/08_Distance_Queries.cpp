#include <bits/stdc++.h>
using namespace std;

struct Tree{
    // Tree Struct by Fusion15
    int root, log, n;
    vector<vector<int>> adj, jump;
    vector<int> depth, parent;

    void dfs(int u){
        for(int v:adj[u]){
            if(v != parent[u]){
                parent[v] = u;
                depth[v] = 1 + depth[u];
                dfs(v);
            }
        }
    }

    void build(){
        for(int i = 0; i<n; i++) jump[i][0] = parent[i];
        for(int i = 1; i<log; i++){
            for(int u = 0; u<n; u++){
                int v = jump[u][i-1];
                if(v==-1) continue;
                jump[u][i] = jump[v][i-1];
            }
        }
    }

    Tree(vector<vector<int>> & a, int r = 0){
        adj = a;
        n = adj.size();
        log = __lg(n) + 1;
        root = r;

        jump.assign(n, vector<int>(log, -1));
        parent.assign(n, -1);
        depth.assign(n, 0);

        dfs(root);
        build();
    }

    int kth_ancestor(int u, int k){
        if(k>depth[u]) return -1;
        for(int i = log-1; i>=0; i--){
            if(k & (1<<i)) u = jump[u][i];
        }
        return u;
    }

    int lca(int u, int v){
        if(depth[u]<depth[v]) swap(u, v);
        u = kth_ancestor(u, depth[u] - depth[v]);
        if(u==v) return u;
        for(int i = log-1; i>=0; i--){
            if(jump[u][i] != jump[v][i]){
                u = jump[u][i];
                v = jump[v][i];
            }
        }
        return jump[u][0];
    }

    int distance(int u, int v){
        int ancestor = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[ancestor];
    }

    bool is_ancestor(int u, int v){
        return lca(u, v) == u;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tree tr(adj);

    while(q--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        cout<<tr.distance(u, v)<<'\n';
    }

    return 0;
}
