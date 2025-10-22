#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    //Binary Search Solution O(nlogn)
    vector<int> lis;
    for(int i : a){
        if(lis.empty() || lis.back() < i) lis.push_back(i);
        else *lower_bound(lis.begin(), lis.end(), i) = i;
    }
    cout<<lis.size();

    return 0;
}

// // Segment Tree Approach O(nlogn)
// #include <bits/stdc++.h>
// using namespace std;

// struct SegTree {
//     //Segment Tree by Fusion15
//     vector<int> tree;
//     int n;

//     //Change
//     int neutral = 0;
//     int merge(int a, int b) {
//         return max(a, b);
//     }

//     void update(int node, int start, int end, int idx, int value) {
//         if(start == end) {
//             tree[node] = value;
//         }
//         else{
//             int mid = (start + end) / 2;
//             if(idx <= mid) {
//                 update(2*node, start, mid, idx, value);
//             }
//             else{
//                 update(2*node+1, mid + 1, end, idx, value);
//             }
//             tree[node] = merge(tree[2*node], tree[2*node+1]);
//         }
//     }

//     int query(int node, int start, int end, int L, int R) {
//         if (R < start || L > end) return neutral;
//         if (L <= start && end <= R) return tree[node];
//         int mid = (start + end) / 2;
//         int l = query(2*node, start, mid, L, R);
//         int r = query(2*node+1, mid + 1, end, L, R);
//         return merge(l, r);
//     }

//     SegTree(int _n){
//         n = _n;
//         tree.resize(4*n, neutral);
//     }

//     int query(int l, int r) {
//         if(l>r) return 0;
//         return query(1, 0, n - 1, l, r);
//     }

//     void update(int idx, int value) {
//         update(1, 0, n - 1, idx, value);
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;

//     vector<int> a(n);
//     for(int &i : a) cin>>i;

//     vector<int> b(a);
//     sort(b.begin(), b.end());
//     b.erase(unique(b.begin(), b.end()), b.end());
//     for(int &i : a) i = lower_bound(b.begin(), b.end(), i) - b.begin();
//     int sz = b.size();
    
//     SegTree st(sz);
//     for(int i : a){
//         int mx = st.query(0, i - 1);
//         st.update(i, mx + 1);
//     }

//     cout<<st.query(0, sz - 1);

//     return 0;
// }
