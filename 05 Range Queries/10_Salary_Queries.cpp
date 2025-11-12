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

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<array<int, 3>> quers(q);
    for(int i = 0; i < q; i++){
        char c;
        cin>>c;
        int x, y;
        cin>>x>>y;
        quers[i] = {c == '?', x, y};
    }

    vector<int> b(a);
    for(auto [t, x, y] : quers){
        if(t == 1){
            b.push_back(x);
            b.push_back(y);
        }
        else b.push_back(y);
    }

    // Coordinate Compression
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int sz = b.size();
    auto compress = [&](int v){
        return lower_bound(b.begin(), b.end(), v) - b.begin(); 
    };

    BIT<int> bit(sz);
    for(int &i : a){
        i = compress(i);
        bit.add(i, 1);
    }

    for(auto [t, x, y] : quers){
        if(t == 0){
            x--;
            bit.add(a[x], -1);
            y = compress(y);
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

// // Ordered Set Approach
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<typename T>
// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, q;
//     cin>>n>>q;

//     vector<int> a(n);
//     for(int &i : a) cin>>i;

//     oset<pair<int, int>> st;
//     for(int i = 0; i < n; i++) st.insert({a[i], i});

//     while(q--){
//         char t;
//         cin>>t;
//         if(t == '!'){
//             int id, v;
//             cin>>id>>v;
//             id--;
//             st.erase({a[id], id});
//             a[id] = v;
//             st.insert({a[id], id});
//         }
//         else{
//             int l, r;
//             cin>>l>>r;
//             int res = st.order_of_key({r, 1e9}) - st.order_of_key({l, 0});
//             cout<<res<<'\n';
//         }
//     }

//     return 0;
// }
