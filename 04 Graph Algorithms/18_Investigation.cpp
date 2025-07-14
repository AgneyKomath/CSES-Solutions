#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
 
int main(){
    ios_base::sync_with_stdio(false);
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
    vector<int> cnt(n, 0);
    vector<int> maxpath(n, 0);
    vector<int> minpath(n, 1e9);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
 
    pq.emplace(0, 0);
    dist[0] = 0;
    cnt[0] = 1;
    maxpath[0] = 0;
    minpath[0] = 0;
 
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] != d) continue;
 
        for(auto [v, w]:adj[u]){
            if(dist[u]+w<dist[v]){
                cnt[v] = 0;
                dist[v] = dist[u] + w;
                maxpath[v] = 0;
                minpath[v] = 1e9;
                pq.emplace(dist[v], v);
            }
            if(dist[u]+w==dist[v]){
                cnt[v] = (cnt[v] + cnt[u]) % mod;
                maxpath[v] = max(maxpath[v], 1 + maxpath[u]);
                minpath[v] = min(minpath[v], 1 + minpath[u]);
            }
        }
    }
 
    cout<<dist[n-1]<<' '<<cnt[n-1]<<' '<<minpath[n-1]<<' '<<maxpath[n-1];
 
}