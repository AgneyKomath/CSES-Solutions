#include <bits/stdc++.h>
using namespace std;

struct BIT{
    //Fenwick Tree by Fusion15
    vector<long long> tree;
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
    
    long long query(int ind){
        long long sum = 0;
        for(int i = ind+1; i>0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }

    long long query(int l, int r){
        if(l>r) return 0;
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    // Coordinate Compression
    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int &i:a){
        i = lower_bound(b.begin(), b.end(), i) - b.begin();
    }
    int sz = b.size();

    BIT bit(sz);

    long long inv = 0;
    for(int i = 0, j = 0; j<n; j++){
        inv += bit.query(a[j]+1, sz-1);
        bit.add(a[j], 1);
        if(j-i+1==k){
            cout<<inv<<' ';
            inv -= bit.query(0, a[i]-1);
            bit.add(a[i], -1);
            i++;
        }
    }

    
    return 0;
}
