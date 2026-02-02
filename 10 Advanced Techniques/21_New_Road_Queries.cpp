#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> f, siz;

    DSU(int n){
        f.resize(n);
        siz.assign(n, 1);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x){
        if(f[x] != x){
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            return false;
        }
        if(siz[y] > siz[x]){
            swap(x, y);
        }
        f[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin>>n>>m>>q;

    DSU dsu(n);

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 1; i <= m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(dsu.merge(u, v)){
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }

    int log = __lg(n) + 1;
    vector<vector<int>> lift(log, vector<int>(n, -1));
    vector<vector<int>> mx(log, vector<int>(n, -1));
    vector<int> depth(n, 0);

    auto dfs = [&](int u, auto &&dfs)->void{
        for(auto [v, w] : adj[u]){
            if(v == lift[0][u]) continue;
            lift[0][v] = u;
            mx[0][v] = w;
            depth[v] = 1 + depth[u];
            dfs(v, dfs);
        }
    };

    for(int i = 0; i < n; i++){
        if(lift[0][i] == -1){
            dfs(i, dfs);
        }
    }

    for(int i = 1; i < log; i++){
        for(int j = 0; j < n; j++){
            if(lift[i - 1][j] == -1) continue;
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][lift[i - 1][j]]);
        }
    }

    auto query = [&](int u, int v){
        if(!dsu.same(u, v)) return -1;
        if(depth[u] < depth[v]) swap(u, v);
        int ddiff = depth[u] - depth[v];
        int res = 0;
        for(int i = 0; i < log; i++){
            if((ddiff >> i) & 1){
                res = max(res, mx[i][u]);
                u = lift[i][u];
            }
        }
        if(u == v) return res;
        for(int i = log - 1; i >= 0; i--){
            if(lift[i][u] != lift[i][v]){
                res = max(res, max(mx[i][u], mx[i][v]));
                u = lift[i][u];
                v = lift[i][v];
            }
        }
        res = max(res, max(mx[0][u], mx[0][v]));
        return res;
    };

    while(q--){
        int u, v;
        cin>>u>>v;
        u--, v--;
        cout<<query(u, v)<<'\n';
    }

    return 0;
}
