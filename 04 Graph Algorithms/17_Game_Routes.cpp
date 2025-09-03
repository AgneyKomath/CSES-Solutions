#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }

    vector<int> dp(n, -1);
    dp[n-1] = 1;

    auto dfs = [&](int u, auto &&dfs){
        if(dp[u] != -1) return dp[u];
        dp[u] = 0;
        for(int v:adj[u]) dp[u] = (dp[u] + dfs(v, dfs)) % mod;
        return dp[u];
    };

    cout<<dfs(0, dfs);
    
    return 0;
}
