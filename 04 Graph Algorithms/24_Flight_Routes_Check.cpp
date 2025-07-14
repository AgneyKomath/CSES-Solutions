#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n), jda(n);

    while(m--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        jda[v].push_back(u);
    }

    vector<int> visited(n,0);
    auto dfs = [&](int node,vector<vector<int>> & adj, auto &&self)->void{
        {};
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = 1;
                self(i, adj, self);
            }
        }
    };
    
    visited[0] = 1;
    dfs(0, adj, dfs);
    
    for(int i = 1;i<n;i++){
        if(visited[i]==0){
            cout<<"NO\n";
            cout<<"1 "<<i+1;
            return 0;
        }
        visited[i] = 0;
    }

    dfs(0, jda, dfs);
    for(int i = 1;i<n;i++){
        if(visited[i]==0){
            cout<<"NO\n";
            cout<<i+1<<" 1";
            return 0;
        }
    }

    cout<<"YES";
    return 0;
}
