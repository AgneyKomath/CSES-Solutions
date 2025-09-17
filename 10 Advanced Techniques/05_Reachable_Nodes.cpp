#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt") 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0; i<n; i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> order;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v:adj[u]){
            if(--indegree[v]==0) q.push(v);
        }
    }

    vector<bitset<50000>> dp(n);
    for(int i = n - 1; i>=0; i--){
        int u = order[i];
        for(int v:adj[u]) dp[u] |= dp[v];
        dp[u].set(u);
    }

    for(auto &i:dp){
        cout<<i.count()<<' ';
    }
    
    return 0;
}
