#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> f, siz;

    DSU(int n){
        f.resize(n);
        siz.assign(n, 1);
        iota(f.begin(),f.end(), 0);
    }

    int find(int x){
        if(f[x] != x){
            f[x] = find(f[x]);
        }
        return f[x];
    }

    int sz(int u){
        return siz[find(u)];
    }

    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(siz[y] > siz[x]) swap(x,y);
        f[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<array<int, 3>> edges(n - 1);

    for(int i = 0; i < n - 1; i++){
        int u, v, s;
        cin>>u>>v>>s;
        u--, v--;
        edges[i] = {s, u, v};
    }

    sort(edges.rbegin(), edges.rend());

    DSU dsu(n);

    long long res = 0;

    for(auto [s, u, v] : edges){
        res += 1ll * s * dsu.sz(u) * dsu.sz(v);
        dsu.merge(u, v);
    }

    cout<<res;

    return 0;
}
