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
    
    DSU dsu(n);

    int cnt = n;
    int mx = 1;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        cnt -= dsu.merge(u, v);
        mx = max(mx, dsu.siz[dsu.find(u)]);
        cout<<cnt<<' '<<mx<<'\n';
    }
    
    return 0;
}
