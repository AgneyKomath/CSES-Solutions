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

    vector<int> subtree(n), distances(n);
    auto dfs1 = [&](int node, int par, auto &&dfs1)->void{
        subtree[node] = 1;
        distances[node] = 0;
        for(int i:adj[node]) if(i != par){
            dfs1(i, node, dfs1);
            subtree[node] += subtree[i];
            distances[node] += distances[i] + subtree[i];
        }
    };
    auto dfs2 = [&](int node, int par, auto &&dfs2)->void{
        if(par != -1){
            distances[node] = distances[par] + n - 2*subtree[node];
        }
        for(int i:adj[node]) if(i != par){
            dfs2(i, node, dfs2);
        } 
    };
    dfs1(0, -1, dfs1);
    dfs2(0, -1, dfs2);
    for(auto i:distances) cout<<i<<' ';
    
    return 0;
}
