#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        adj[u].emplace_back(v, w);
    }

    vector<ll> dist(n, INF);
    vector<int> cnt(n, 0), mn(n, n), mx(n, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[0] = mn[0] = mx[0] = 0;
    cnt[0] = 1;
    pq.emplace(0, 0);

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] < d) continue;
        for(auto [v, w] : adj[u]){
            ll nd = d + w;
            if(dist[v] > nd){
                dist[v] = nd;
                cnt[v] = 0;
                mn[v] = n;
                mx[v] = 0;
                pq.emplace(nd, v);
            }
            if(dist[v] == nd){
                cnt[v] = (cnt[v] + cnt[u]) % mod;
                mn[v] = min(mn[v], 1 + mn[u]);
                mx[v] = max(mx[v], 1 + mx[u]);
            }
        }
    }

    cout<<dist[n - 1]<<' '<<cnt[n - 1]<<' '<<mn[n - 1]<<' '<<mx[n - 1];

    return 0;
}
