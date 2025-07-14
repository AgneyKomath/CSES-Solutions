#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }

    vector<int> vis(n, 0);
    vector<int> prev(n, -1);
    vector<int> cycle;

    auto dfs = [&](int u, auto &&dfs){
        vis[u] = 1;
        for(int v:adj[u]){
            if(!cycle.empty()) return;
            if(vis[v]==0){
                prev[v] = u;
                dfs(v, dfs);
            }   
            else if(vis[v]==1){
                cycle.push_back(v);
                int curr = u;
                while(curr != v){
                    cycle.push_back(curr);
                    curr = prev[curr];
                }
                cycle.push_back(v);
            }
        }
        vis[u] = 2;
    };

    for(int i = 0; i<n && cycle.empty(); i++){
        if(!vis[i]) dfs(i, dfs);
    }

    if(cycle.empty()){
        cout<<"IMPOSSIBLE";
    }
    else{
        reverse(cycle.begin(), cycle.end());
        cout<<cycle.size()<<'\n';
        for(int i:cycle) cout<<i+1<<" ";
    }

    return 0;
}
