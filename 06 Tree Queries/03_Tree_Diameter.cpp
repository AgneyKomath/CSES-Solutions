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

    int res = 0;
    auto dfs = [&](int u, int p, auto &&dfs)->int{
        int mx = 0;
        for(int v : adj[u]){
            if(v == p) continue;
            int val = dfs(v, u, dfs);
            res = max(res, mx + val);
            mx = max(mx, val);
        }
        return 1 + mx;
    };
    dfs(0, -1, dfs);

    cout<<res;

    return 0;
}
