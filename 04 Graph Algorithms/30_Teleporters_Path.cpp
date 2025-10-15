#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> indeg(n, 0), outdeg(n, 0);
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }

    /*
    Euler Path in Directed Graph
    Graph Should be Connected
    Each Node must have equal indegree and outdegree except 1 and n
    */

    for(int i = 1; i < n - 1; i++){
        if(indeg[i] != outdeg[i]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    if(indeg[0] != outdeg[0] - 1 || indeg[n - 1] != outdeg[n - 1] + 1){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    // Hierholzer's algorithm
    vector<int> path;
    auto dfs = [&](int u, auto &&dfs)->void{
        while(!adj[u].empty()){
            auto v = adj[u].back();
            adj[u].pop_back();
            dfs(v, dfs);
        }
        path.push_back(u);
    };

    dfs(0, dfs);
    if(path.size() != m + 1) cout<<"IMPOSSIBLE";
    else{
        reverse(path.begin(), path.end());
        for(int u : path) cout<<u + 1<<' ';
    }

    return 0;
}
