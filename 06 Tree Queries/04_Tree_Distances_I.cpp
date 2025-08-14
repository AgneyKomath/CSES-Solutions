#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

    auto dfs=[&](int node, int d, vector<int> &dist, auto &&dfs){
        if(dist[node] != -1) return;
        dist[node] = d;
        for(int i:adj[node]) dfs(i, d+1, dist, dfs);
    };
    
    vector<int> d1(n, -1), d2(n, -1), d3(n,  -1);
    
    dfs(0, 0, d1, dfs);
    int end1 = max_element(d1.begin(), d1.end()) - d1.begin();

    dfs(end1, 0, d2, dfs);
    int end2 = max_element(d2.begin(), d2.end()) - d2.begin();

    dfs(end2, 0, d3, dfs);
    
    for(int i = 0; i<n; i++){
        cout<<max(d2[i], d3[i])<<' ';
    }

    return 0;
}
