#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i = 1; i<n; i++){
        int p;
        cin>>p;
        p--;
        adj[p].push_back(i);
    }

    vector<int> res(n, 0);
    auto dfs = [&](int u, auto &&dfs)->void{
        for(int v:adj[u]){
            dfs(v, dfs);
            res[u] += 1 + res[v]; 
        }
    };

    dfs(0, dfs);

    for(int i:res) cout<<i<<' ';
    
    return 0;
}
