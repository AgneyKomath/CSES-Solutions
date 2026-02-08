#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Small to Large Merging
    vector<set<int>> st(n);
    vector<int> res(n);
    auto dfs = [&](int u, int p, auto &&dfs)->void{
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u, dfs);
            if(st[v].size() > st[u].size()) swap(st[u], st[v]);
            for(int x : st[v]) st[u].insert(x);
        }
        st[u].insert(a[u]);
        res[u] = st[u].size();
    };
    dfs(0, -1, dfs);

    for(int i : res) cout<<i<<' ';

    return 0;
}