#include <bits/stdc++.h>
using namespace std;

struct RollbackDSU{
    vector<int> f, siz;

    stack<pair<int, int>> ops;

    RollbackDSU(int n){
        f.resize(n);
        siz.assign(n, 1);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x){
        while(f[x] != x){
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            ops.emplace(x, y);
            return false;
        }
        if(siz[y] > siz[x]){
            swap(x, y);
        }
        f[y] = x;
        siz[x] += siz[y];
        ops.emplace(x, y);
        return true;
    }

    bool rollback(){
        auto [x, y] = ops.top();
        ops.pop();
        if(x == y) return false;
        f[y] = y;
        siz[x] -= siz[y];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin>>n>>m>>q;

    map<pair<int, int>, vector<int>> mp;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(u > v) swap(u, v);
        mp[{u, v}].push_back(0);
    }

    for(int i = 1; i <= q; i++){
        int t, u, v;
        cin>>t>>u>>v;
        u--, v--;
        if(u > v) swap(u, v);
        mp[{u, v}].push_back(i);
    }

    int k = q + 1; // time from 0 to k
    vector<vector<pair<int, int>>> tree(4 * k);

    auto add = [&](int node, int start, int end, int L, int R, int u, int v, auto &&add){
        if(end < L || start > R) return;
        if(start >= L && end <= R){
            tree[node].emplace_back(u, v);
            return;
        }
        int mid = (start + end) / 2;
        add(2 * node, start, mid, L, R, u, v, add);
        add(2 * node + 1, mid + 1, end, L, R, u, v, add);
    };

    for(auto &[e, vec] : mp){
        auto [u, v] = e;
        int sz = vec.size();
        if(sz & 1) vec.push_back(k);
        for(int i = 0; i < sz; i += 2){
            add(1, 0, k - 1, vec[i], vec[i + 1] - 1, u, v, add);
        }
    }

    RollbackDSU dsu(n);
    int res = n;
    auto dfs = [&](int node, int start, int end, auto &&dfs)->void{
        for(auto &[u, v] : tree[node]){
            res -= dsu.merge(u, v);
        }
        if(start == end){
            cout<<res<<' ';
        }
        else{
            int mid = (start + end) / 2;
            dfs(2 * node, start, mid, dfs);
            dfs(2 * node + 1, mid + 1, end, dfs);
        }
        for(auto &[u, v] : tree[node]){
            res += dsu.rollback();
        }
    };

    dfs(1, 0, k - 1, dfs);

    return 0;
}
