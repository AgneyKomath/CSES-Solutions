#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](int u, int p, int d, auto &&dfs)->pair<int, int>{
        pair<int, int> res = {d, u};
        for(int v:adj[u]){
            if(v==p) continue;
            res = max(res, dfs(v, u, d+1, dfs));
        }
        return res;
    };

    int farthestNode = dfs(0, -1, 0, dfs).second;
    int diameter = dfs(farthestNode, -1, 0, dfs).first;

    cout<<diameter;
    
    return 0;
}
