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

    vector<array<int, 3>> queries(q);
    for(auto &[t, x, y]:queries){
        char c;
        cin>>c>>x>>y;
        t = (c=='?');
    }

    // Coordinate Compression
    vector<int> b(a);
    for(auto [t, x, y]:queries){
        if(t==0) b.push_back(y);
        else{
            b.push_back(x);
            b.push_back(y);
        }
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto compress = [&](int val)->int{
        return lower_bound(b.begin(), b.end(), val) - b.begin();
    };
    int sz = b.size();

    BIT bit(sz);
    for(int &i:a){
        i = compress(i);
        bit.add(i, 1);
    }
    
    for(auto [t, x, y]:queries){
        if(t==0){
            x--;
            y = compress(y);
            bit.add(a[x], -1);
            a[x] = y;
            bit.add(a[x], 1);
        }
        else{
            x = compress(x);
            y = compress(y);
            cout<<bit.query(x, y)<<'\n';
        }
    }

    return 0;
}
