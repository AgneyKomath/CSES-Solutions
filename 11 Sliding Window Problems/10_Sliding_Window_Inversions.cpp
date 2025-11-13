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

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());

    BIT<int> bit(n);

    long long inv = 0;
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        inv += bit.query(a[i] + 1, n - 1);
        bit.add(a[i], 1);
        if(i >= k - 1){
            cout<<inv<<' ';
            inv -= bit.query(a[i - k + 1] - 1);
            bit.add(a[i - k + 1], -1);
        }
    }

    return 0;
}
