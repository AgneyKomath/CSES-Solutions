#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT{
    //Fenwick Tree by Fusion15
    vector<T> arr;
    vector<T> tree;
    int n;

    BIT(){
        n = 0;
    }

    BIT(int _n){
        n = _n;
        tree.resize(n + 1, 0);
        arr.resize(n, 0);
    }

    template<typename U>
    BIT(vector<U> &a){
        n = a.size();
        arr.resize(n, 0);
        tree.resize(n + 1, 0);
        // O(n) build
        for(int i = 0; i < n; i++){
            arr[i] = a[i];
            int id = i + 1;
            tree[id] += arr[i];
            int j = id + (id&-id);
            if(j <= n) tree[j] += tree[id];
        }
    }

    void add(int id, T val){
        arr[id] += val;
        for(int i = id + 1; i <= n; i += i&-i){
            tree[i] += val;
        }
    }

    void update(int id, T val){
        T diff = val - arr[id];
        add(id, diff);
    }

    T query(int id){
        T sum = T(0);
        for(int i = id + 1; i > 0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }

    T query(int l, int r){
        if(l > r) return T(0);
        return query(r) - query(l - 1);
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

    // Euler Tour
    BIT<long long> bit(n);
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
    };
    dfs(0, -1, dfs);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int u, x;
            cin>>u>>x;
            u--;
            bit.update(tin[u], x);
        }
        else{
            int u;
            cin>>u;
            u--;
            cout<<bit.query(tin[u], tout[u])<<'\n';
        }
    }

    return 0;
}