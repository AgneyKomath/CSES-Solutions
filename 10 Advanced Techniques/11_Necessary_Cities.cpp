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
    vector<int> res;
    
    int cnt0 = 0;
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
                if(u == 0) cnt0++;
                dfs(v, u, dfs);
                low[u] = min(low[u], low[v]);
                if(u != 0 && low[v] >= tin[u]){
                    res.push_back(u);
                }
            }
        }
    };

    dfs(0, -1, dfs);

    if(cnt0 >= 2) res.push_back(0);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    cout<<res.size()<<'\n';
    for(int i : res) cout<<i + 1<<' ';

    return 0;
}
