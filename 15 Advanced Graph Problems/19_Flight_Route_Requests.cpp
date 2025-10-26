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

    int n, m;
    cin>>n>>m;

    DSU dsu(n);
    vector<int> indeg(n, 0);
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        dsu.merge(u, v);
        indeg[v]++;
    }

    // First Divide Graph into Connected Components
    // For Each Component of size n: 
    // If it is fully weakly connected, arrange it in a chain and add n - 1 to res
    // If it contains a strongly connected component, arrange it in a cycle and add n to res

    vector<vector<int>> comps(n);
    for(int i = 0; i < n; i++){
        comps[dsu.find(i)].push_back(i);
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        if(comps[i].empty()) continue;

        int sz = comps[i].size();

        queue<int> q;
        for(int u : comps[i]){
            if(indeg[u] == 0) q.push(u);
        }

        int topoSize = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topoSize++;
            for(int v : adj[u]){
                if(--indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        res += topoSize != sz ? sz : sz - 1; 
    }

    cout<<res;

    return 0;
}
