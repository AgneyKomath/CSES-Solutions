#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
    }

    vector<vector<int>> dp(n, vector<int>(1<<n, -1));
    fill(dp[n - 1].begin(), dp[n - 1].end(), 0);
    dp[n - 1][1 << (n - 1)] = 1;

    auto f = [&](int u, int mask, auto &&f){
        if(dp[u][mask] != -1) return dp[u][mask];
        dp[u][mask] = 0;
        int newMask = mask & ~(1 << u);
        for(int v:adj[u]){
            if((newMask >> v) & 1){
                dp[u][mask] = (dp[u][mask] + f(v, newMask, f)) % mod;
            }
        }
        return dp[u][mask];
    };

    cout<<f(0, (1<<n) - 1, f);
    
    return 0;
}
