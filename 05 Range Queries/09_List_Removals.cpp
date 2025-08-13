#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    ordered_set st;
    for(int i = 0; i<n; i++){
        int v;
        cin>>v;
        st.insert({i, v});
    }

    for(int i = 0; i<n; i++){
        int id;
        cin>>id;
        id--;
        auto it = st.find_by_order(id);
        cout<<it->second<<' ';
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

//     void build(int node, int start, int end, vector<int> &arr) {
//         if(start == end) tree[node] = arr[start];
//         else{
//             int mid = (start + end) / 2;
//             build(2*node, start, mid, arr);
//             build(2*node+1, mid + 1, end, arr);
//             tree[node] = merge(tree[2*node], tree[2*node+1]);
//         }
//     }

//     void update(int node, int start, int end, int idx, int val) {
//         if(start == end) {
//             tree[node] = val;
//         }
//         else{
//             int mid = (start + end) / 2;
//             if(idx <= mid) {
//                 update(2*node, start, mid, idx, val);
//             }
//             else{
//                 update(2*node+1, mid + 1, end, idx, val);
//             }
//             tree[node] = merge(tree[2*node], tree[2*node+1]);
//         }
//     }

//     int walk(int node, int start, int end, int val){
//         if(start==end) return start;
//         int mid = (start + end) / 2;
//         if(tree[2*node]>=val){
//             return walk(2*node, start, mid, val);
//         }
//         else{
//             return walk(2*node+1, mid+1, end, val - tree[2*node]);
//         }
//     }

//     SegTree(vector<int> &a) {
//         n = a.size();
//         tree.resize(4 * n);
//         build(1, 0, n - 1, a);
//     }

//     void update(int idx, int val) {
//         update(1, 0, n - 1, idx, val);
//     }
    
//     int walk(int val){
//         return walk(1, 0, n-1, val);
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;

//     vector<int> a(n);
//     for(int &i:a) cin>>i;

//     vector<int> ids(n, 1);
//     SegTree st(ids);

//     for(int i = 0; i<n; i++){
//         int p;
//         cin>>p;
//         int id = st.walk(p);
//         cout<<a[id]<<' ';
//         st.update(id, 0);
//     }
    
//     return 0;
// }
