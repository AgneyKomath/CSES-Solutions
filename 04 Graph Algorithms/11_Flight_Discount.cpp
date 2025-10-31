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

    vector<array<ll, 2>> dist(n, {INF, INF});
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    dist[0][0] = dist[0][1] = 0;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto [d, u, t] = pq.top();
        pq.pop();
        if(dist[u][t] < d) continue;
        for(auto [v, w] : adj[u]){
            if(dist[v][t] > dist[u][t] + w){
                dist[v][t] = dist[u][t] + w;
                pq.push({dist[v][t], v, t});
            }
            if(t == 0 && dist[v][1] > dist[u][0] + w / 2){
                dist[v][1] = dist[u][0] + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout<<dist[n - 1][1];

    return 0;
}
