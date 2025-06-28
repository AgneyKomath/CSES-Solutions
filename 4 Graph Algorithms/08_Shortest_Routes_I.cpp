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
    
    int n,m;
    cin>>n>>m;

    vector<vector<pii>> adj(n);
    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        a--;b--;
        adj[a].push_back({b,d});
    }

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dist(n,1e18);

    dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(dist[u] != d) continue;

        for(auto [v,w]:adj[u]){
            if(dist[u] + w <dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<dist[i]<<" \n"[i==n-1];
    
    return 0;
}
