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
        adj[v].push_back(u);
    }

    vector<bool> vis(n, 0);
    vector<int> prev(n, -1);
    vector<int> cycle;

    auto dfs = [&](int u, auto &&dfs)->void{
        vis[u] = 1;
        for(int v:adj[u]){
            if(!cycle.empty()) break;
            if(v == prev[u]) continue;
            
            if(!vis[v]){
                prev[v] = u;
                dfs(v, dfs);
            }
            else{
                int curr = u;
                cycle.push_back(v);
                while(curr != v){
                    cycle.push_back(curr);
                    curr = prev[curr];
                }
                cycle.push_back(v);
            } 
        }
    };

    for(int i = 0; i<n; i++){
        if(!cycle.empty()) break;
        if(!vis[i]){
            dfs(i, dfs);
        }
    }

    if(cycle.empty()){ 
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<cycle.size()<<'\n';
        for(int i:cycle) cout<<i+1<<' ';
    }
    
    return 0;
}
