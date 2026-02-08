#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    int log = __lg(n) + 1;

    vector<vector<int>> jump(log, vector<int>(n, -1)), adj(n);
    for(int i = 1; i < n; i++){
        int u;
        cin>>u;
        u--;
        adj[u].push_back(i);
        jump[0][i] = u;
    }

    for(int i = 1; i < log; i++){
        for(int j = 0; j < n; j++){
            if(jump[i - 1][j] == -1) continue;
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }

    vector<int> depth(n, 0);
    auto dfs = [&](int u, auto &&dfs)->void{
        for(int v : adj[u]){
            depth[v] = 1 + depth[u];
            dfs(v, dfs);
        }
    };
    dfs(0, dfs);

    auto lca = [&](int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for(int i = 0; i < log; i++){
            if((diff >> i) & 1){
                u = jump[i][u];
            }
        }

        if(u == v) return u;

        for(int i = log - 1; i >= 0; i--){
            if(jump[i][u] != jump[i][v]){
                u = jump[i][u];
                v = jump[i][v];
            }
        }

        return jump[0][u];
    };

    while(q--){
        int u, v;
        cin>>u>>v;
        u--, v--;
        int res = lca(u, v) + 1;
        cout<<res<<'\n';
    }

    return 0;
}
