#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long pref = 0;
    long long suff = 0;
    long long mxSub = 0;
    long long fullSub = 0;
    Node(){}
    Node(int val){
        pref = max(0, val);
        suff = max(0, val);
        mxSub = max(0, val);
        fullSub = val;
    }
    Node(long long pf, long long sf, long long mxsb, long long flsb){
        pref = max(0ll, pf);
        suff = max(0ll, sf);
        mxSub = max(0ll, mxsb);
        fullSub = flsb;
    }
};

template <typename T>
class SegTree {
    //Segment tree by Fusion15
    vector<T> tree;
    vector<int> arr;
    int n;

    //Change
    T neutral = Node();
    T merge(T a, T b) {
        long long pref = max(a.pref, a.fullSub + b.pref);
        long long suff = max(b.suff, b.fullSub + a.suff);
        long long mxSub = max({a.mxSub, b.mxSub, a.suff + b.pref});
        long long fullSub = a.fullSub + b.fullSub;
        return Node(pref, suff, mxSub, fullSub); 
    }

    void build(int node, int start, int end) {
        if(start == end){
            //Change 
            tree[node] = Node(arr[start]);
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
            //Change
            arr[idx] = value;
            tree[node] = Node(value);
        }
        else{
            int mid = (start + end) / 2;
            if(idx <= mid) {
                update(2*node, start, mid, idx, value);
            }
            else{
                update(2*node+1, mid + 1, end, idx, value);
            }
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    T query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return neutral;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        T l = query(2*node, start, mid, L, R);
        T r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

public:
    SegTree(int _n){
        n = _n;
        tree.resize(4*n, neutral);
        arr.resize(n, neutral);
    }
    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4*n, neutral);
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;
    
    vector<int> a(n);
    for(int &i:a) cin>>i;

    SegTree<Node> st(a);

    while(q--){
        int l, r;
        cin>>l>>r;
        l--;r--;
        cout<<st.query(l, r).mxSub<<'\n';
    }
    
    return 0;
}
