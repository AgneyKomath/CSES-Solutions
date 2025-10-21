#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    
    vector<array<int, 3>> edges(m);
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edges[i] = {u, v, w};
    }

    vector<long long> dist(n, 0);
    vector<int> prev(n, -1);
    int lastnode;
    for(int i = 0; i<n; i++){
        lastnode = -1;
        for(auto [u, v, w]:edges){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                prev[v] = u;
                lastnode = v;
            }
        }
    }
    
    if(lastnode == -1){
        cout<<"NO";
        return 0;
    }

    int curr = lastnode;
    vector<int> vis(n, 0), path;
    while(!vis[curr]){
        vis[curr] = 1;
        path.push_back(curr);
        curr = prev[curr];
    }
    path.push_back(curr);
    reverse(path.begin(), path.end());
    while(path.back() != curr) path.pop_back();

    cout<<"YES\n";
    for(int i : path) cout<<i + 1<<' ';

    return 0;
}
