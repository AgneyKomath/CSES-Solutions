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
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> dist(n,-1);
    auto dfs=[&](int node, int d, auto &&self){
        if(dist[node]!=-1) return;
        dist[node] = d;
        for(int i:adj[node]) self(i, d+1, self);
    };
    
    dfs(0, 0, dfs);

    int u = 0;
    for(int i = 1;i<n;i++){
        if(dist[i]>dist[u]) u = i;
    }

    fill(dist.begin(), dist.end(), -1);

    dfs(u, 0, dfs);

    cout<<*max_element(dist.begin(), dist.end());
    
    return 0;
}
