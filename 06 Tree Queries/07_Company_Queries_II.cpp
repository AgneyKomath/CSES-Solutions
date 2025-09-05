#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    int log = __lg(n) + 1;

    vector<vector<int>> adj(n);
    vector<vector<int>> jump(log, vector<int>(n, -1));
    for(int i = 1; i<n; i++){
        cin>>jump[0][i];
        jump[0][i]--;
        adj[jump[0][i]].push_back(i);
    }

    for(int i = 1; i<log; i++){
        for(int j = 0; j<n; j++){
            int v = jump[i-1][j];
            if(v==-1) continue;
            jump[i][j] = jump[i-1][v];
        }
    }

    vector<int> depth(n, 0);
    auto dfs = [&](int u, auto &&dfs)->void{
        for(int v:adj[u]){
            if(v != jump[0][u]){
                depth[v] = 1 + depth[u];
                dfs(v, dfs);
            }
        }
    };
    dfs(0, dfs);

    auto kth_ancestor = [&](int u, int k){
        for(int i = log-1; i>=0 && u != -1; i--){
            if(k&(1<<i)) u = jump[i][u];
        }
        return u;
    };

    auto lca = [&](int u, int v){
        if(depth[u]<depth[v]) swap(u, v);

        // Make Them Same Level First
        u = kth_ancestor(u, depth[u] - depth[v]);
        
        if(u==v) return u;

        // While Jumps are not same lift them. At the end the parent will be the LCA
        for(int i = log-1; i>=0; i--){
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
        u--;v--;

        cout<<lca(u, v) + 1<<'\n';
    }

    return 0;
}