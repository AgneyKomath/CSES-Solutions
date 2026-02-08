#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT{
    //Fenwick Tree by Fusion15
    vector<T> tree;
    int n;

    BIT(int _n){
        n = _n;
        tree.resize(n + 1, 0);
    }

    void add(int id, T val){
        for(int i = id + 1; i <= n; i += i&-i){
            tree[i] += val;
        }
    }

    T query(int id){
        T sum = T(0);
        for(int i = id + 1; i > 0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

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

    BIT<long long> bit(n + 1);
    vector<int> tin(n, 0), tout(n, 0);
    int timer = 0;
    auto dfs = [&](int u, int p, auto &&dfs)->void{
        tin[u] = timer++;
        bit.add(tin[u], a[u]);
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u, dfs);
        }
        tout[u] = timer - 1;
        bit.add(tout[u] + 1, -a[u]);
    };
    dfs(0, -1, dfs);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int u, x;
            cin>>u>>x;
            u--;
            bit.add(tin[u], x - a[u]);
            bit.add(tout[u] + 1, a[u] - x);
            a[u] = x;
        }
        else{
            int u;
            cin>>u;
            u--;
            // root to node sum
            cout<<bit.query(tin[u])<<'\n';
            // for node to node path do query(u) + query(v) - 2 * query(lca(u, v)) + a[lca(u, v)]
        }
    }

    return 0;
}