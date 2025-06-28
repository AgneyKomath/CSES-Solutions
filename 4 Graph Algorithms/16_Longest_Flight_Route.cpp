#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> pii;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    while(m--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }

    vector<int> dist(n,-1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> parent(n,-1);

    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d, tp] = pq.top();
        pq.pop();
        if(dist[tp]!=d) continue;
        
        for(int i : adj[tp]){
            if(dist[tp]+1>dist[i]){
                dist[i] = dist[tp]+1;
                parent[i] = tp;
                pq.push({dist[i],i});
            }
        }
    }

    if(dist[n-1]==-1){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int> res;
    int u = n-1;
    while(u != 0){
        res.push_back(u);
        u = parent[u];
    }
    res.push_back(0);

    int sz = res.size();
    cout<<sz<<'\n';
    for(int i = sz-1;i>=0;i--) cout<<res[i]+1<<' ';

    
    return 0;
}


