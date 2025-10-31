#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]){
            if(--indeg[v] == 0){
                q.push(v);
            }
        }
    }

    if(topo.size() != n) cout<<"IMPOSSIBLE";
    else for(int i : topo) cout<<i + 1<<' ';

    return 0;
}
