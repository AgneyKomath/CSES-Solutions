#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = -1;
    vector<int> sub(n, 1);
    auto dfs = [&](int u, int p, auto &&dfs){
        if(res != -1) return;
        int mx = 0;
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u, dfs);
            sub[u] += sub[v];
            mx = max(mx, sub[v]);
        }
        mx = max(mx, n - sub[u]);
        if(mx <= n / 2) res = u;
    };
    dfs(0, -1, dfs);

    cout<<res + 1;

    return 0;
}