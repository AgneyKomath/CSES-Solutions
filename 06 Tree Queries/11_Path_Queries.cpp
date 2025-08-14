#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Euler Tour
    vector<int> tin(n), tout(n);
    int timer = 0;
    auto dfs = [&](int u, int p, auto &&dfs)->void{
        tin[u] = timer++;
        for(int v:adj[u]){
            if(v==p) continue;
            dfs(v, u, dfs);
        }
        tout[u] = timer;
    };
    dfs(0, -1, dfs);

    //Fenwick Tree
    vector<long long> tree(n+2, 0);
    auto add = [&](int ind, long long val){
        for(int i = ind+1; i<=n+1; i += i&-i){
            tree[i] += val;
        }
    };
    auto query = [&](int ind){
        long long res = 0;
        for(int i = ind+1; i; i -= i&-i){
            res += tree[i];
        }
        return res;
    };

    // Difference Array
    for(int i = 0; i<n; i++){
        add(tin[i], +a[i]);
        add(tout[i], -a[i]);
    }

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int u, val;
            cin>>u>>val;
            u--;
            int prev = a[u];
            add(tin[u], val - prev);
            add(tout[u], prev - val);
            a[u] = val;
        }
        else{
            int u;
            cin>>u;
            u--;
            // root to node sum
            cout<<query(tin[u])<<'\n';
            // for node to node path do sum(a) + sum(b) - 2 * sum(lca(a, b)) + val(lca(a, b))
        }
    }
    
    return 0;
}
