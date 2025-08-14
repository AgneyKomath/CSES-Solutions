#include <bits/stdc++.h>
using namespace std;

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

    int mxLog = __lg(n) + 1;

    vector<vector<int>> jump(n, vector<int>(mxLog+1));

    vector<int> depth(n, 0);
    auto dfs = [&](int u, int p, auto &&dfs)->void{
        jump[u][0] = p; 
        for(int v:adj[u]){
            if(v==p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, dfs);
        }
    };
    dfs(0, -1, dfs);

    for(int p = 1; p<=mxLog; p++){
        for(int u = 0; u<n; u++){
            int mid = jump[u][p-1];
            jump[u][p] = (mid == -1 ? -1 : jump[mid][p-1]);
        }
    }

    auto kth_ancestor = [&](int u, int k){
        for(int p = 0; p<=mxLog; p++){
            if((k&(1<<p))){
                u = jump[u][p];
                if(u==-1) break;
            }
        }
        return u;
    };

    auto lca = [&](int u, int v){
        if(depth[u]<depth[v]) swap(u, v);
        u = kth_ancestor(u, depth[u] - depth[v]);
        if(u==v) return v;
        for(int i = mxLog; i>=0; i--){
            if(jump[u][i] != jump[v][i]){
                u = jump[u][i];
                v = jump[v][i];
            }
        }
        return jump[u][0];
    };

    while(q--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        int res = depth[u] + depth[v] - 2*depth[lca(u, v)];
        cout<<res<<'\n';
    }

    return 0;
}
