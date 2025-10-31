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
    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(vis[v]) continue;
            prev[v] = u;

            if(v == n - 1){
                vector<int> path;
                while(v != -1){
                    path.push_back(v);
                    v = prev[v];
                }
                reverse(path.begin(), path.end());
                cout<<path.size()<<'\n';
                for(int i : path) cout<<i + 1<<' ';
                return 0;
            }

            vis[v] = 1;
            q.emplace(v);
        }
    }

    cout<<"IMPOSSIBLE";

    return 0;
}
