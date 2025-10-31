#include <bits/stdc++.h>
using namespace std;

// DFS Solution
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    auto dfs = [&](int u, auto &&dfs)->void{
        for(int v : adj[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            dfs(v, dfs);
        }
    };

    vector<int> reps;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        reps.push_back(i);
        dfs(i, dfs);
    }

    int sz = reps.size();
    cout<<sz - 1<<'\n';
    for(int i = 1; i < sz; i++){
        cout<<reps[i - 1] + 1<<' '<<reps[i] + 1<<'\n';
    }

    return 0;
}

// DSU Solution
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    //DSU
    vector<int> f(n), siz(n, 1);
    iota(f.begin(), f.end(), 0);
    auto find = [&](int x, auto &&find)->int{
        if(f[x] != x) f[x] = find(f[x], find);
        return f[x];
    };
    auto merge = [&](int x, int y){
        x = find(x, find);
        y = find(y, find);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        f[y] = x;
        siz[x] += siz[y];
        return true;
    };

    int cnt = n;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        cnt -= merge(u, v);
    }

    cout<<cnt - 1<<'\n';
    for(int i = 1; i < n; i++){
        if(merge(0, i)){
            cout<<1<<' '<<i + 1<<'\n';
        }
    }

    return 0;
}
