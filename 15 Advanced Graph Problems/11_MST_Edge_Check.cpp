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

    bool same(int x, int y){
        return find(x) == find(y);
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

    int n, m;
    cin>>n>>m;

    map<int, vector<array<int, 3>>> mp;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        mp[w].push_back({u, v, i});
    }

    DSU dsu(n);
    vector<int> res(m);

    for(auto &[w, vec] : mp){
        for(auto &[u, v, id] : vec){
            res[id] = !dsu.same(u, v);
        }
        for(auto &[u, v, id] : vec){
            dsu.merge(u, v);
        }
    }

    for(int v : res){
        cout<<(v ? "YES" : "NO")<<'\n';
    }

    return 0;
}
