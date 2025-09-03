#include <bits/stdc++.h>
using namespace std;

vector<bool> check(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> vis(n, 0);
    auto dfs = [&](int u, auto &&dfs)->void{
        vis[u] = 1;
        for(int v:adj[u]){
            if(!vis[v]) dfs(v, dfs);
        }
    };
    dfs(0, dfs);
    return vis;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n), revadj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        revadj[v].push_back(u);
    }

    auto v1 = check(adj), v2 = check(revadj);

    for(int i = 1; i<n; i++){
        if(v1[i] && v2[i]) continue;
        
        cout<<"NO\n";
        if(v1[i]) cout<<i+1<<' '<<1<<'\n';
        else cout<<1<<' '<<i+1<<'\n';
        return 0;
    }

    cout<<"YES";
    
    return 0;
}
