#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

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
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] != d) continue;
        for(auto [v, w] : adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v); 
            }
        }
    }

    for(ll i : dist) cout<<i<<' ';

    return 0;
}
