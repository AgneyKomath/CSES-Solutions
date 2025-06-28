#include <bits/stdc++.h>
#define int long long
using namespace std;

static constexpr int mxn = 5e4;
typedef bitset<mxn> bts;

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

    vector<bts> dp(n);

    auto dfs = [&](int node, auto &&self){
        if(dp[node].count()) return dp[node];
        bts res = 0;
        for(int j:adj[node]){
            res |= self(j, self);
        }
        res.set(node);
        return dp[node] = res;
    };

    for(int i = 0;i<n;i++){
        if(dp[i].count()) continue;
        dfs(i, dfs);
    }

    for(int i=0;i<n;i++){
        cout<<dp[i].count()<<' ';
    }
    
    return 0;
}
