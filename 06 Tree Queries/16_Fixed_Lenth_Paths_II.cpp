#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Centroid{
    int n;
    ll res;
    vector<int> sub, vis;
    vector<vector<int>> adj;

    Centroid(vector<vector<int>> &a){
        adj = a;
        n = adj.size();
        sub.assign(n, 0);
        vis.assign(n, 0);
    }

    ll findPaths(int k1, int k2){
        res = 0;
        fill(vis.begin(), vis.end(), 0);
        decompose(0, k1, k2);
        return res;
    }

    void decompose(int entry, int k1, int k2){
        int c = findCentroid(entry);
        vis[c] = 1;
        vector<int> cnt(1, 1);
        auto get_cnt = [&](int id){
            if(id < 0 || id >= cnt.size()) return 0;
            return cnt[id];
        };
        int base_curr = (k1 == 1);
        for(int v : adj[c]){
            if(vis[v]) continue;
            vector<int> dists(1, 0);
            getDists(v, c, 1, k2, dists);
            for(int d = 1, curr = base_curr; d < (int)dists.size(); d++){
                res += 1ll * dists[d] * curr;
                curr += get_cnt(k1 - (d + 1));
                curr -= get_cnt(k2 - d);
            }
            if(cnt.size() <= dists.size()) cnt.resize(dists.size(), 0);
            for(int d = 1; d < (int)dists.size(); d++){
                cnt[d] += dists[d];
                if(d >= k1 - 1 && d <= k2 - 1) base_curr += dists[d];
            } 
        }
        for(int v : adj[c]){
            if(vis[v]) continue;
            decompose(v, k1, k2);
        }
    }

    void getDists(int u, int p, int d, int k, vector<int> &dists){
        if(d > k) return;
        if(dists.size() <= d) dists.resize(d + 1, 0);
        dists[d]++;
        for(int v : adj[u]){
            if(v == p || vis[v]) continue;
            getDists(v, u, d + 1, k, dists);
        }
    };

    int findCentroid(int src){
        dfsSub(src, -1);
        return dfsCent(src, -1, sub[src]);
    }

    void dfsSub(int u, int p){
        sub[u] = 1;
        for(int v : adj[u]){
            if(v == p || vis[v]) continue;
            dfsSub(v, u);
            sub[u] += sub[v];
        }
    }

    int dfsCent(int u, int p, int sz){
        for(int v : adj[u]){
            if(v == p || vis[v]) continue;
            if(sub[v] > sz / 2) return dfsCent(v, u, sz);
        }
        return u;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k1, k2;
    cin>>n>>k1>>k2;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Centroid cent(adj);

    ll res = cent.findPaths(k1, k2);
    cout<<res;

    return 0;
}