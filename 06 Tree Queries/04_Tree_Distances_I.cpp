#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](int u, int p, vector<int> &d, auto &&dfs)->void{
        for(int v : adj[u]){
            if(v == p) continue;
            d[v] = 1 + d[u];
            dfs(v, u, d, dfs);
        }
    };

    vector<int> d1(n, 0), d2(n, 0), d3(n, 0);

    dfs(0, -1, d1, dfs);
    int u1 = max_element(d1.begin(), d1.end()) - d1.begin();

    dfs(u1, -1, d2, dfs);
    int u2 = max_element(d2.begin(), d2.end()) - d2.begin();

    dfs(u2, -1, d3, dfs);

    for(int i = 0; i < n; i++){
        cout<<max(d2[i], d3[i])<<' ';
    }

    return 0;
}
