#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct DSU{
    vector<int> f, siz;

    DSU(int n){
        f.resize(n);
        siz.assign(n, 1);
        iota(f.begin(), f.end(), 0);
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
        if(x == y){
            return false;
        }
        if(siz[y] > siz[x]){
            swap(x, y);
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
    int res = 1;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(!dsu.merge(u, v)){
            res = res * 2 % mod;
        }
    }

    cout<<res;

    return 0;
}


// // DFS Solution
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m;
//     cin>>n>>m;

//     vector<vector<int>> adj(n);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin>>u>>v;
//         u--, v--;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int res = 1;
//     vector<int> tin(n, -1);
//     auto dfs = [&](int u, int p, auto &&dfs)->void{
//         for(int v : adj[u]){
//             if(v == p) continue;
//             if(tin[v] != -1){
//                 if(tin[v] < tin[u]){
//                     res = res * 2 % mod;
//                 }
//             }
//             else{
//                 tin[v] = tin[u] + 1;
//                 dfs(v, u, dfs);
//             }
//         }
//     };

//     for(int i = 0; i < n; i++){
//         if(tin[i] == -1){
//             tin[i] = 0;
//             dfs(i, -1, dfs);
//         } 
//     }

//     cout<<res;

//     return 0;
// }
