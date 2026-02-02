#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, 0), low(n, 0), vis(n, 0);
    vector<pair<int, int>> res;
 
    auto dfs = [&](int u, int p, auto &&dfs)->void{
        vis[u] = 1;
        low[u] = tin[u];
        for(int v : adj[u]){
            if(v == p) continue;
            if(vis[v]){
                low[u] = min(low[u], tin[v]);
            }
            else{
                tin[v] = 1 + tin[u];
                dfs(v, u, dfs);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u]){
                    res.emplace_back(u, v);
                }
            }
        }
    };

    dfs(0, -1, dfs);

    cout<<res.size()<<'\n';
    for(auto [u, v] : res){
        cout<<u + 1<<' '<<v + 1<<'\n';
    }

    return 0;
}
