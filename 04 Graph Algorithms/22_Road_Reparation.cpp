#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> f, siz;

    DSU(int n){
        f.resize(n);
        siz.assign(n,1);
        iota(f.begin(),f.end(),0ll);
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
        
        if(x==y){
            return false;
        }
        if(siz[y]>siz[x]){
            swap(x,y);
        }
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
    
    vector<array<int, 3>> edges(m);
    for(auto &[w, u, v]:edges){
        cin>>u>>v>>w;
        u--;v--;
    }

    sort(edges.begin(), edges.end());

    long long res = 0;
    int cnt = n;

    DSU dsu(n);

    for(auto [w, u, v]:edges){
        if(dsu.merge(u, v)){
            res += w;
            if(--cnt==1) break;
        }
    }

    if(cnt>1) cout<<"IMPOSSIBLE";
    else cout<<res;
    
    return 0;
}
