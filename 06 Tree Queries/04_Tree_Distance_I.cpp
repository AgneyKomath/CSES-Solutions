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

    auto dfs=[&](int node, int d, vector<int> &dist, auto &&self){
        if(dist[node]!=-1) return;
        dist[node] = d;
        for(int i:adj[node]) self(i, d+1, dist, self);
    };
    
    vector<int> d1(n,-1), d2(n,-1), d3(n, -1);
    
    dfs(0, 0, d1, dfs);
    int u = 0;
    for(int i = 0;i<n;i++){
        if(d1[i]>d1[u]) u = i;
    }

    dfs(u, 0, d2, dfs);
    int v = u;
    for(int i = 0;i<n;i++){
        if(d2[i]>d2[v]) v = i;
    }

    dfs(v, 0, d3, dfs);
    for(int i = 0;i<n;i++){
        cout<<max(d2[i], d3[i])<<' ';
    }


    return 0;
}
