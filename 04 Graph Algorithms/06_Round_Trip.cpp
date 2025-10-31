#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> prev(n, -1), vis(n, 0);

    auto dfs = [&](int u, auto &&dfs)->void{
        vis[u] = 1;
        for(int v : adj[u]){
            if(v == prev[u]) continue;

            if(vis[v]){
                vector<int> cycle;
                cycle.push_back(v);
                int curr = u;
                while(curr != v){
                    cycle.push_back(curr);
                    curr = prev[curr];
                }
                cycle.push_back(v);
                cout<<cycle.size()<<'\n';
                for(int i : cycle) cout<<i + 1<<' ';
                exit(0);
            }

            prev[v] = u;
            dfs(v, dfs);
        }
    };

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        dfs(i, dfs);
    }

    cout<<"IMPOSSIBLE";

    return 0;
}
