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
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    BIT<long long> diff(n + 1);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int l, r, v;
            cin>>l>>r>>v;
            l--, r--;
            diff.add(l, v);
            diff.add(r + 1, -v);
        }
        else{
            int id;
            cin>>id;
            id--;
            cout<<a[id] + diff.query(id)<<'\n';
        }
    }

    return 0;
}
