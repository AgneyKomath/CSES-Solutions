#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // No need for DP array lol
    auto dfs = [&](int node, int par, auto &&dfs)->pair<int, int>{        
        int curr = 0;
        int bestDiff = 0;
        for(int i:adj[node]) if(i != par){
            auto [notChosen, chosen] = dfs(i, node, dfs);
            curr += notChosen;
            bestDiff = max(bestDiff, 1 + chosen - notChosen);
        }
        return {curr + bestDiff, curr};
    };
    cout<<dfs(0, -1, dfs).first;


    // // DP
    // vector<array<int, 2>> dp(n);
    // auto dfs = [&](int node, int par, auto &&dfs)->void{        
    //     int curr = 0;
    //     int bestDiff = 0;
    //     for(int i:adj[node]) if(i != par){
    //         dfs(i, node, dfs);
    //         curr += dp[i][0];
    //         bestDiff = max(bestDiff, 1 + dp[i][1] - dp[i][0]);
    //     }
    //     // When node is already matched to parent chose best matching for all child nodes
    //     dp[node][1] = curr;
    //     // When node not matched, chose edge that gives best differnce and chose best matching for all other child nodes
    //     dp[node][0] = curr + bestDiff;
    // };
    // dfs(0, -1, dfs);
    // cout<<dp[0][0];
    
    return 0;
}
