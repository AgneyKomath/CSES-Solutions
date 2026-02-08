#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sub(n, 1);
    vector<long long> dist(n, 0);

    auto dfs = [&](int u, int p, auto &&dfs)->void{
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u, dfs);
            sub[u] += sub[v];
            dist[u] += dist[v] + sub[v];
        }
    };
    dfs(0, -1, dfs);

    auto reroot = [&](int u, int p, auto &&reroot)->void{
        for(int v : adj[u]){
            if(v == p) continue;
            dist[v] = dist[u] + n - 2 * sub[v];
            reroot(v, u, reroot);    
        }
    };
    reroot(0, -1, reroot);

    for(long long i : dist) cout<<i<<' ';

    return 0;
}
