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
    
    int n, m, k;
    cin>>n>>m>>k;

    set<pair<int, int>> initial;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        initial.insert({min(u, v), max(u, v)});
    }

    vector<pair<int, int>> toRemove(k);
    for(int i = 0; i < k; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        toRemove[i] = {u, v};
        initial.erase({min(u, v), max(u, v)});
    }

    DSU dsu(n);
    int cnt = n;
    for(auto [u, v] : initial) cnt -= dsu.merge(u, v);

    vector<int> res(k);
    res[k - 1] = cnt;
    for(int i = k - 1; i > 0; i--){
        auto [u, v] = toRemove[i];
        cnt -= dsu.merge(u, v);
        res[i - 1] = cnt;
    }

    for(int i : res) cout<<i<<' ';

    return 0;
}
