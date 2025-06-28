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

    bool flag = true;
    vector<int> team(n, 0);
    auto dfs = [&](int u, int curr, auto &&dfs)->void{
        curr = 3 - curr;
        for(int v:adj[u]){
            if(team[v]){
                if(team[v] != curr) flag = false;
            }
            else{
                team[v] = curr;
                dfs(v, curr, dfs);
            }
        }
    };

    for(int i = 0; i<n; i++){
        if(!team[i]){
            team[i] = 1;
            dfs(i, 1, dfs);
        }
    }

    if(!flag){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i:team) cout<<i<<" ";
    }
    
    return 0;
}
