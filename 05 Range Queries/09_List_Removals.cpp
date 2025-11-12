#include <bits/stdc++.h>
using namespace std;

// Ordered Set Approach
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    oset<int> st;
    for(int i = 0; i < n; i++) st.insert(i);

    for(int i = 0; i<n; i++){
        int p;
        cin>>p;
        p--;
        auto it = st.find_by_order(p);
        cout<<a[*it]<<' ';
        st.erase(it);
    }

    return 0;
}

// // Segment Tree Approach
// struct SegTree {
//     //Segment Tree by Fusion15
//     vector<int> tree;
//     int n;

//     //Change
//     int neutral = 0;
//     int merge(int a, int b) {
//         return a + b;
//     }

//     void build(int node, int start, int end, vector<int> &a) {
//         if(start == end) tree[node] = a[start];
//         else{
//             int mid = (start + end) / 2;
//             build(2 * node, start, mid, a);
//             build(2 * node + 1, mid + 1, end, a);
//             tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
//         }
//     }

//     void update(int node, int start, int end, int id, int val) {
//         if(start == end) tree[node] = val;
//         else{
//             int mid = (start + end) / 2;
//             if(id <= mid) update(2 * node, start, mid, id, val);
//             else update(2 * node + 1, mid + 1, end, id, val);
//             tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
//         }
//     }

//     int walk(int node, int start, int end, int val){
//         if(start == end) return start;
//         int mid = (start + end) / 2;
//         if(tree[2 * node] >= val) return walk(2 * node, start, mid, val);
//         return walk(2 * node + 1, mid + 1, end, val - tree[2 * node]);
//     }

//     SegTree(int _n) {
//         n = _n;
//         tree.resize(4 * n);
//         vector<int> a(n, 1);
//         build(1, 0, n - 1, a);
//     }

//     int walk(int v){
//         return walk(1, 0, n - 1, v);
//     }

//     void update(int id, int val) {
//         update(1, 0, n - 1, id, val);
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;

//     vector<int> a(n);
//     for(int &i : a) cin>>i;

//     SegTree st(n);

//     for(int i = 0; i < n; i++){
//         int p;
//         cin>>p;
//         int id = st.walk(p);
//         st.update(id, 0);
//         cout<<a[id]<<' ';
//     }

//     return 0;
// }
