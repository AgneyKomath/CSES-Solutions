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

    vector<long long> dist(n, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] != d) continue;
        for(auto [v, w]:adj[u]){
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for(auto i:dist) cout<<i<<' ';
    
    return 0;
}
