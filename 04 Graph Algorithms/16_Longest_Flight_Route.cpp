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
    }

    vector<int> dp(n, -1), next(n, -1);
    dp[n - 1] = 1;

    auto dfs = [&](int u, auto &&dfs){
        if(dp[u] != -1) return;
        dp[u] = 0;
        for(int v : adj[u]){
            dfs(v, dfs);
            if(dp[v] == 0) continue;
            if(1 + dp[v] > dp[u]){
                dp[u] = 1 + dp[v];
                next[u] = v;
            }
        }
    };

    dfs(0, dfs);

    if(dp[0] == 0){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    cout<<dp[0]<<'\n';

    int curr = 0;
    while(curr != -1){
        cout<<curr + 1<<' ';
        curr = next[curr];
    }

    return 0;
}
