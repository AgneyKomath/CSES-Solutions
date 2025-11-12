#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT{
    //Fenwick Tree by Fusion15
    vector<T> arr;
    vector<T> tree;
    int n;

    BIT(){
        n = 0;
    }

    BIT(int _n){
        n = _n;
        tree.resize(n + 1, 0);
        arr.resize(n, 0);
    }

    template<typename U>
    BIT(vector<U> &a){
        n = a.size();
        arr.resize(n, 0);
        tree.resize(n + 1, 0);
        // O(n) build
        for(int i = 0; i < n; i++){
            arr[i] += a[i];
            int id = i + 1;
            tree[id] += arr[i];
            int j = id + (id&-id);
            if(j <= n) tree[j] += tree[id];
        }
    }

    void add(int id, T val){
        arr[id] += val;
        for(int i = id + 1; i <= n; i += i&-i){
            tree[i] += val;
        }
    }

    void update(int id, T val){
        T diff = val - arr[id];
        add(id, diff);
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

    BIT<long long> bit(a);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int id, val;
            cin>>id>>val;
            id--;
            bit.update(id, val);
        }
        else{
            int l, r;
            cin>>l>>r;
            l--, r--;
            cout<<bit.query(l, r)<<'\n';
        }
    }

    return 0;
}
