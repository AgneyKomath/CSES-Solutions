#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n, 0);
    vector<int> par(n, -1);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            par[v] = u;
            vis[v] = 1;
            q.push(v);
            if(v==n-1){
                vector<int> res;
                int curr = v;
                while(curr != -1){
                    res.push_back(curr);
                    curr = par[curr];
                }
                cout<<res.size()<<'\n';
                for(int i = res.size() - 1; i>=0; i--){
                    cout<<res[i]+1<<' ';
                }
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";
    
    return 0;
}
