#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        adj[u].emplace_back(v, w);
    }

    vector<int> viscount(n, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);

    vector<ll> res(k);
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(viscount[u] >= k) continue;
        if(u == n - 1) res[viscount[u]] = d;
        viscount[u]++;
        for(auto [v, w] : adj[u]){
            if(viscount[v] < k) pq.emplace(d + w, v);
        }
    }

    for(ll i : res) cout<<i<<' ';

    return 0;
}
