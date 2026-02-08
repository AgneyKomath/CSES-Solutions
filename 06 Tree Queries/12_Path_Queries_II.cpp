#include <bits/stdc++.h>
using namespace std;

struct IterSegTree{
    //Iterative Segment Tree by Fusion15
    vector<int> tree, a;
    int n;

    //Change
    static constexpr int neutral = -1e9;
    static int merge(int a, int b){
        return max(a, b);
    }

    IterSegTree(){
        n = 0;
    }

    IterSegTree(int _n){
        n = _n;
        tree.resize(2 * n, neutral);
        a.resize(n, neutral);
    }

    IterSegTree(vector<int> &arr){
        a = arr;
        n = a.size();
        tree.resize(2 * n);
        build();
    }

    void build(){
        for(int i = 0; i < n; i++) tree[n + i] = a[i];
        for(int i = n - 1; i >= 1; i--){
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int pos, int val){
        a[pos] = val;
        pos += n;
        tree[pos] = val;
        while(pos > 1){
            pos >>= 1;
            tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    int query(int l, int r){
        l += n, r += n + 1;
        int res = neutral;
        while(l < r){
            if(l & 1) res = merge(res, tree[l++]);
            if(r & 1) res = merge(res, tree[--r]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

struct HLD{
    // HLD Struct by Fusion15
    int n, root, cur_pos;
    vector<vector<int>> adj;
    vector<int> par, depth, heavy, head, pos;
    IterSegTree st;

    HLD(vector<vector<int>> & _adj, vector<int> & a, int r = 0){
        adj = _adj;
        n = adj.size();
        root = r;
        init();
        vector<int> order(n);
        for(int i = 0; i < n; i++){
            order[pos[i]] = a[i]; 
        }
        st = IterSegTree(order);
    }

    void init(){
        par.resize(n);
        depth.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        cur_pos = 0;
        depth[root] = 0;
        par[root] = -1;
        dfs(root);
        decompose(root, root);
    }

    int dfs(int u){
        int size = 1;
        int maxv = 0;
        for(int v : adj[u]){
            if(v == par[u]) continue;
            par[v] = u;
            depth[v] = 1 + depth[u];
            int vsize = dfs(v);
            size += vsize;
            if(vsize > maxv){
                maxv = vsize;
                heavy[u] = v; 
            }
        }
        return size;
    }

    void decompose(int u, int h){
        head[u] = h, pos[u] = cur_pos++;
        if(heavy[u] != -1){
            decompose(heavy[u], h);
        }
        for(int v : adj[u]){
            if(v != par[u] && v != heavy[u]){
                decompose(v, v);
            }
        }
    }

    int query(int u, int v){
        int res = st.neutral;
        for(; head[u] != head[v]; v = par[head[v]]){
            if(depth[head[u]] > depth[head[v]]) swap(u, v);
            int curr = st.query(pos[head[v]], pos[v]);
            res = st.merge(res, curr);
        }
        if(depth[u] > depth[v]) swap(u, v);
        int last = st.query(pos[u], pos[v]);
        res = st.merge(res, last);
        return res;
    };

    void update(int u, int x){
        st.update(pos[u], x);
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

    HLD hld(adj, a);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int u, x;
            cin>>u>>x;
            u--;
            hld.update(u, x);
        }
        else{
            int u, v;
            cin>>u>>v;
            u--, v--;
            cout<<hld.query(u, v)<<' ';
        }
    }

    return 0;
}