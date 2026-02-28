#include <bits/stdc++.h>
using namespace std;

// Small to Large Merging (Much Faster)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long res = 0;

    vector<vector<int>> dists(n);
    auto dfs = [&](int u, int p, auto &&dfs)->void{
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u, dfs);
            int n = dists[u].size(), m = dists[v].size();
            if(m >= k) res += dists[v][m - k];
            if(m > n){
                swap(dists[v], dists[u]);
                swap(n, m);
            }
            for(int i = 1; i <= m; i++){
                int opp = k - i;
                if(opp > 0 && opp <= n){
                    res += 1ll * dists[v][m - i] * dists[u][n - opp];
                }
            }
            for(int i = 1; i <= m; i++){
                dists[u][n - i] += dists[v][m - i];
            }
        }
        dists[u].push_back(1);
    };
    dfs(0, -1, dfs);

    cout<<res;

    return 0;
}

// // Centroid Decomposition
// using ll = long long;
// struct Centroid{
//     int n;
//     ll res;
//     vector<int> sub, vis;
//     vector<vector<int>> adj;

//     Centroid(vector<vector<int>> &a){
//         adj = a;
//         n = adj.size();
//         sub.assign(n, 0);
//         vis.assign(n, 0);
//     }

//     ll findPaths(int k){
//         res = 0;
//         fill(vis.begin(), vis.end(), 0);
//         decompose(0, k);
//         return res;
//     }

//     void decompose(int entry, int k){
//         int c = findCentroid(entry);
//         vis[c] = 1;
//         vector<int> cnt(1, 1);
//         for(int v : adj[c]){
//             if(vis[v]) continue;
//             vector<int> dists;
//             getDists(v, c, 1, k, dists);
//             for(int d : dists){
//                 int need = k - d;
//                 if(need < 0) continue;
//                 if(need < (int)cnt.size()) res += cnt[need];
//             }

//             int mx = 0;
//             for(int d : dists) mx = max(mx, d);
//             if((int)cnt.size() <= mx) cnt.resize(mx + 1, 0);
//             for(int d : dists) cnt[d]++;
//         }
//         for(int v : adj[c]){
//             if(vis[v]) continue;
//             decompose(v, k);
//         }
//     }

//     void getDists(int u, int p, int d, int k, vector<int> &dists){
//         if(d > k) return;
//         dists.push_back(d);
//         for(int v : adj[u]){
//             if(v == p || vis[v]) continue;
//             getDists(v, u, d + 1, k, dists);
//         }
//     };

//     int findCentroid(int src){
//         dfsSub(src, -1);
//         return dfsCent(src, -1, sub[src]);
//     }

//     void dfsSub(int u, int p){
//         sub[u] = 1;
//         for(int v : adj[u]){
//             if(v == p || vis[v]) continue;
//             dfsSub(v, u);
//             sub[u] += sub[v];
//         }
//     }

//     int dfsCent(int u, int p, int sz){
//         for(int v : adj[u]){
//             if(v == p || vis[v]) continue;
//             if(sub[v] > sz / 2) return dfsCent(v, u, sz);
//         }
//         return u;
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, k;
//     cin>>n>>k;

//     vector<vector<int>> adj(n);
//     for(int i = 0; i < n - 1; i++){
//         int u, v;
//         cin>>u>>v;
//         u--, v--;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     Centroid cent(adj);

//     ll res = cent.findPaths(k);
//     cout<<res;

//     return 0;
// }
