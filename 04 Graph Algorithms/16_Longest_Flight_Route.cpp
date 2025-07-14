#include <bits/stdc++.h>
using namespace std;

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
        dp[u] = -1e9;
        for(int v:adj[u]){
            dp[u] = max(dp[u], 1 + dfs(v, dfs));
        }
        return dp[u];
    };
 
    for(int i = 0; i<n; i++){
        dfs(i, dfs);
    }
 
    if(dp[0]<-1e8){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<dp[0]<<'\n';
        int curr = 0;
        while(curr != n-1){
            cout<<curr+1<<" ";
            for(int i:adj[curr]){
                if(dp[i] == dp[curr]-1){
                    curr = i;
                    break;
                }
            }
        }
        cout<<n;
    }
    
    return 0;
}


