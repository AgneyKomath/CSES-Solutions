#include <bits/stdc++.h>
using namespace std;

struct BIT{
    //Fenwick Tree by Fusion15
    vector<int> tree;
    int n;
    
    BIT(int _n){
        n = _n;
        tree.resize(n+1, 0);
    }
    
    void add(int ind, int val){
        for(int i=ind+1; i<=n; i += i&-i){
            tree[i] += val;
        }
    }

    int query(int ind){
        int sum = 0;
        for(int i = ind+1; i>0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }

    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    // Coordinate Compression
    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int sz = b.size();
    
    // Store in each index if a previous index has same value
    BIT bit(n);
    vector<vector<int>> mp(sz);
    for(int i = n-1; i>=0; i--){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(!mp[a[i]].empty()){
            bit.add(mp[a[i]].back(), 1);
        }
        mp[a[i]].push_back(i);
    }

    vector<vector<pair<int, int>>> quers(n);
    for(int i = 0; i<q; i++){
        int x, y;
        cin>>x>>y;
        quers[x-1].emplace_back(y-1, i);
    }

    vector<int> res(q);
    for(int i = 0; i<n; i++){
        for(auto [r, id]:quers[i]){
            int v = bit.query(i, r);
            res[id] = (r-i+1) - v;
        }
        
        mp[a[i]].pop_back();
        if(!mp[a[i]].empty()){
            bit.add(mp[a[i]].back(), -1);
        }
    }
    
    for(int i:res) cout<<i<<'\n';
    
    return 0;
}
