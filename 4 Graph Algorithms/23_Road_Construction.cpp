#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU{
    vector<int> f, siz;
    int mx = 1;

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

        mx = max(mx,siz[x]+siz[y]);

        siz[x] += siz[y];
        return true;
    }

    int getMax(){
        return mx;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    DSU dsu(n);

    int comps = n;

    while(m--){
        int a, b;
        cin>>a>>b;
        a--;b--;

        if(dsu.merge(a,b)) comps--;

        int mxc = dsu.getMax();

        cout<<comps<<' '<<mxc<<'\n';
    }
    
    
    return 0;
}
