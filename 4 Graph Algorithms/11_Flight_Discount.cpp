#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> pii;
typedef array<int,3> a3;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    vector<vector<pii>> adj(n, vector<pii>(m));
    
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].emplace_back(b,c);
    }

    int src = 0, dest = n-1;

    priority_queue<a3,vector<a3>,greater<a3>> pq;
    vector<int> dist(n,1e18);

    dist[src] = 0;
    pq.push({0,src,1});
    while(!pq.empty()){
        auto [d,u,flag] = pq.top();
        pq.pop();
        if(dist[u] != d) continue;

        for(auto [v,w]:adj[u]){
            if(dist[u] + w <dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v, 1});
                if(flag){
                    pq.push({dist[u] + w/2, v});
                }
            }
        }
    }


    return 0;
}

