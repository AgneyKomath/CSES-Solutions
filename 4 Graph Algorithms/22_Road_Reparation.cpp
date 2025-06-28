#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU{
    vector<int> f, siz;

    DSU(int n){
        f.resize(n);
        siz.resize(n,1);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x){
        if(x!=f[x]) f[x] = find(f[x]);
        return f[x];
    }

    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return false;

        if(f[y]>f[x]) swap(x,y);
        f[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    
    vector<array<int,3>> edges(m);

    for(int i = 0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int comps = n;
    int res = 0;
    for(auto &[d, a, b]:edges){
        if(dsu.merge(a,b)){
            res += d;
            comps--;
        }
    }

    if(comps != 1){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    cout<<res;

    return 0;
}
