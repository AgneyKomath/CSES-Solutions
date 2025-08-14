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

    vector<int> subtree(n, 1);
    vector<long long> distances(n, 0);

    auto dfs1 = [&](int u, int p, auto &&dfs1)->void{
        for(int v:adj[u]){
            if(v==p) continue;
            dfs1(v, u, dfs1);
            subtree[u] += subtree[v];
            distances[u] += distances[v] + subtree[v];
        }
    };

    auto dfs2 = [&](int u, int p, auto &&dfs2)->void{
        for(int v:adj[u]){
            if(v==p) continue;
            distances[v] = distances[u] + n - 2 * subtree[v]; 
            dfs2(v, u, dfs2);
        } 
    };

    dfs1(0, -1, dfs1);
    dfs2(0, -1, dfs2);

    for(auto i:distances){
        cout<<i<<' ';
    }
    
    return 0;
}
