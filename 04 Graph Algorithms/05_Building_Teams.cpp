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

    vector<int> col(n, 0);
    auto dfs = [&](int u, int c, auto &&dfs)->void{
        col[u] = c;
        for(int v : adj[u]){
            if(col[v] == 0) dfs(v, 3 - c, dfs);
            else if(col[v] == col[u]){
                cout<<"IMPOSSIBLE";
                exit(0);
            }
        }
    };

    for(int i = 0; i < n; i++){
        if(!col[i]) dfs(i, 1, dfs);
    }

    for(int i : col) cout<<i<<' ';

    return 0;
}
