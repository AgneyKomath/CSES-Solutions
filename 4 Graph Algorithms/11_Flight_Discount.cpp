#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--;v--;
        adj[u].emplace_back(v, w);
    }

    vector<array<long long, 2>> dist(n, {1e18, 1e18});
    priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> pq;

    dist[0] = {0, 0};
    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto [d, t, u] = pq.top();
        pq.pop();
        if(dist[u][t] != d) continue;

        for(auto [v, w]:adj[u]){
            if(dist[u][t] + w < dist[v][t]){
                dist[v][t] = dist[u][t] + w;
                pq.push({dist[v][t], t, v});
            }
            if(t==0 && dist[u][0] + w/2 < dist[v][1]){
                dist[v][1] = dist[u][0] + w/2;
                pq.push({dist[v][1], 1, v});
            }
        }
    }

    cout<<dist[n-1][1];

    return 0;
}
