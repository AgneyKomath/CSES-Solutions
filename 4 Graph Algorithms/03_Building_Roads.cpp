#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    //DSU
    vector<int> f(n), siz(n, 1);
    iota(f.begin(), f.end(), 0);
    auto find = [&](int x, auto &&find)->int{
        if(f[x] != f[f[x]]) f[x] = find(f[x], find);
        return f[x];
    };
    auto merge = [&](int x, int y){
        x = find(x, find);
        y = find(y, find);
        if(x==y) return false;
        if(siz[x]<siz[y]) swap(x, y);
        f[y] = x;
        siz[x] += siz[y];
        return true;
    };
    
    int cnt = n;
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        cnt -= merge(a, b);
    }

    cout<<cnt-1<<'\n';
    for(int i = 1; i<n; i++){
        if(merge(0, i)){
            cout<<1<<' '<<i+1<<'\n';
        }
    }
    
    return 0;
}
