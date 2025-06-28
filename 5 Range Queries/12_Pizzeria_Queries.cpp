//Segment Tree of pairs
#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
class SegTree {
    //Template by Fusion15
    vector<T> tree;
    vector<int> arr;
    int n;

    //Change
    T neutralValue = {1e9,1e9};
    T merge(T a, T b) {
        return {min(a.first,b.first),min(a.second,b.second)};
    }

    void build(int node, int start, int end) {
        if(start == end){
            tree[node] = {
                arr[start] + start,
                arr[start] + n-start-1
            };
        }
        else{
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid + 1, end);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if(start == end) {
            arr[idx] = value;
            tree[node] = {
                value + start,
                value + n-start-1
            };
        }
        else{
            int mid = (start + end) / 2;
            if(start <= idx && idx <= mid) {
                update(2*node, start, mid, idx, value);
            }
            else{
                update(2*node+1, mid + 1, end, idx, value);
            }
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    T query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return neutralValue;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        T l = query(2*node, start, mid, L, R);
        T r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

public:
    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4 * n,neutralValue);
        arr = a;
        build(1, 0, n - 1);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    SegTree<pair<int,int>> st(a);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int k,x;
            cin>>k>>x;
            k--;
            st.update(k,x);
        }
        else{
            int k;
            cin>>k;
            k--;

            auto [temp1,back] = st.query(0,k); 
            auto [forw,temp2] = st.query(k,n-1); 

            back -= (n-k-1);
            forw -= k;
            cout<<min(back,forw)<<'\n';

        }
    }
    
    return 0;
}


// //2 Segment Trees;
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// class SegTree {
//     //Segment Tree by Fusion15
//     vector<int> tree;
//     vector<int> arr;
//     int n;

//     //Change
//     int neutral = 1e9;
//     int merge(int a, int b) {
//         return min(a,b);
//     }

//     void build(int node, int start, int end) {
//         if(start == end) tree[node] = arr[start];
//         else{
//             int mid = (start + end) / 2;
//             build(2*node, start, mid);
//             build(2*node+1, mid + 1, end);
//             tree[node] = merge(tree[2*node], tree[2*node+1]);
//         }
//     }

//     void update(int node, int start, int end, int idx, int value) {
//         if(start == end) {
//             arr[idx] = value;
//             tree[node] = value;
//         }
//         else{
//             int mid = (start + end) / 2;
//             if(start <= idx && idx <= mid) {
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

// public:
//     SegTree() {}
//     SegTree(int n) : n(n), tree(4 * n, neutral), arr(n,neutral) {}
//     SegTree(const vector<int> &a) {
//         n = a.size();
//         tree.resize(4 * n);
//         arr = a;
//         build(1, 0, n - 1);
//     }

//     int query(int l, int r) {
//         return query(1, 0, n - 1, l, r);
//     }

//     void update(int idx, int value) {
//         update(1, 0, n - 1, idx, value);
//     }
// };

// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n,q;
//     cin>>n>>q;
//     vector<int> a(n);
//     for(int &i:a) cin>>i;

//     SegTree forw(n), back(n);

//     auto pull=[&](int i){
//         forw.update(i,a[i]-i);
//         back.update(i,a[i]+i);
//     };

//     for(int i=0;i<n;i++) pull(i);

//     while(q--){
//         int type;
//         cin>>type;
//         if(type==1){
//             int k,x;
//             cin>>k>>x;
//             k--;
//             a[k] = x;
//             pull(k);
//         }
//         else{
//             int k;
//             cin>>k;
//             k--;
//             int D = forw.query(0,k) + k;
//             int U = back.query(k,n-1) - k;
//             cout<<min(D,U)<<'\n';
//         }
//     } 
    
//     return 0;
// }

