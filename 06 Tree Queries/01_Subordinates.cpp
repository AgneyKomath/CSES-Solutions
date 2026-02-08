#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++){
        int u;
        cin>>u;
        adj[u - 1].push_back(i);
    }

    vector<int> sub(n, 0);
    auto dfs = [&](int u, auto &&dfs)->void{
        for(int v : adj[u]){
            dfs(v, dfs);
            sub[u] += 1 + sub[v];
        }
    };
    dfs(0, dfs);

    for(int i : sub) cout<<i<<' ';

    return 0;
}
