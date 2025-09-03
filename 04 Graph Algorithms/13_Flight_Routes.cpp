#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--;v--;
        adj[u].emplace_back(v, w);
    }

    vector<priority_queue<ll>> dist(n);
    dist[0].push(0);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u].top()<d) continue;
        for(auto [v, w]:adj[u]){
            ll nd = d + w;
            if((int)dist[v].size()==k && dist[v].top()<=nd) continue;
            dist[v].push(nd);
            while((int)dist[v].size()>k) dist[v].pop();
            pq.emplace(nd, v);
        }
    }

    vector<ll> res;
    while(!dist[n-1].empty()){
        res.push_back(dist[n-1].top());
        dist[n-1].pop();
    }

    for(int i = k-1; i>=0; i--) cout<<res[i]<<' ';
    
    return 0;
}
