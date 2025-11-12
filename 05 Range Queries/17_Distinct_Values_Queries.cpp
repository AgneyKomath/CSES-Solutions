#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT{
    //Fenwick Tree by Fusion15
    vector<T> tree;
    int n;

    BIT(int _n){
        n = _n;
        tree.resize(n + 1, 0);
    }

    void add(int id, T val){
        for(int i = id + 1; i <= n; i += i&-i){
            tree[i] += val;
        }
    }

    void set(int id){
        add(id, 1);
    }

    void reset(int id){
        add(id, -1);
    }

    T query(int id){
        T sum = 0;
        for(int i = id + 1; i > 0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }

    T query(int l, int r){
        if(l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int sz = b.size();

    BIT<int> bit(n);
    vector<int> prev(sz, -1), next(n, -1);
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(prev[a[i]] != -1){
            next[prev[a[i]]] = i;
            bit.set(i);
        }
        prev[a[i]] = i;
    }

    vector<array<int, 3>> quers(q);
    for(int i = 0; i < q; i++){
        int l, r;
        cin>>l>>r;
        l--, r--;
        quers[i] = {l, r, i};
    }
    sort(quers.begin(), quers.end());

    vector<int> res(q);
    int curr = 0;
    for(auto [l, r, id] : quers){
        while(curr < l){
            if(next[curr] != -1){
                bit.reset(next[curr]);
            }
            curr++;
        }
        res[id] = r - l + 1 - bit.query(l, r);
    }

    for(int i : res) cout<<i<<'\n';

    return 0;
}
