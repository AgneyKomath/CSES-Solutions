#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n), radj(n);
    vector<array<int, 3>> edges(m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        adj[u].emplace_back(v, w);
        radj[v].emplace_back(u, w);
        edges[i] = {u, v, w};
    }

    auto dfs = [](int u, vector<int> &r, vector<vector<pair<int, int>>> &a, auto &&dfs)->void{
        r[u] = 1;
        for(auto [v, w] : a[u]){
            if(r[v]) continue;
            dfs(v, r, a, dfs);
        }
    };

    vector<int> r1(n, 0), r2(n, 0);
    dfs(0, r1, adj, dfs);
    dfs(n - 1, r2, radj, dfs);

    vector<ll> dist(n, -INF);
    dist[0] = 0;

    bool change = false;
    for(int i = 0; i < n; i++){
        change = false;
        for(auto [u, v, w] : edges){
            if(!r1[u] || !r2[u] || !r1[v] || !r2[v]) continue;
            if(dist[v] < dist[u] + w){
                dist[v] = dist[u] + w;
                change = true;
            }
        }
        if(!change) break;
    }

    cout<<(change ? -1 : dist[n - 1]);

    return 0;
}
