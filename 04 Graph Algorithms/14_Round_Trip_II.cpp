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
    }

    vector<int> prev(n, -1), vis(n, 0);

    auto dfs = [&](int u, auto &&dfs)->void{
        vis[u] = 1;
        for(int v : adj[u]){
            if(vis[v] == 0){
                prev[v] = u;
                dfs(v, dfs);
            }
            else if(vis[v] == 1){
                vector<int> cycle;
                cycle.push_back(v);
                int curr = u;
                while(curr != v){
                    cycle.push_back(curr);
                    curr = prev[curr];
                }
                cycle.push_back(v);
                reverse(cycle.begin(), cycle.end());
                cout<<cycle.size()<<'\n';
                for(int i : cycle) cout<<i + 1<<' ';
                exit(0);
            }
        }
        vis[u] = 2;
    };

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        dfs(i, dfs);
    }

    cout<<"IMPOSSIBLE";

    return 0;
}
