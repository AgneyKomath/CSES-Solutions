#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    while(m--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }

    vector<int> dp(n,-1);
    dp[n-1] = 1;

    auto dfs = [&](int node, auto &&self){
        if(dp[node]!=-1) return dp[node];
        
        int res = 0;
        for(int i:adj[node]){
            res = (res + self(i, self)) % mod;
        }
        dp[node] = res;
        return res;
    };
    
    dfs(0, dfs);
    cout<<dp[0];

    return 0;
}
