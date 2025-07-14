#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
    int pref;
    int suff;
    int sub;
    int full;

    Node(){
        pref = 0;
        suff=0;
        sub=0;
        full=0;
    }
    Node(int _pref, int _suff, int _sub, int _full){
        pref = max(0ll, _pref);
        suff = max(0ll, _suff);
        sub = max(0ll, _sub);
        full = _full;
    }
    Node(int v){
        int temp = max(0ll,v);
        pref = temp;
        suff = temp;
        sub = temp;
        full = v;
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
        int pref = max(a.pref, a.full + b.pref);
        int suff = max(b.suff, b.full + a.suff);
        int sub = max({a.sub, b.sub, a.suff + b.pref});
        int full = a.full + b.full;
        return Node(pref, suff, sub, full); 
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
    SegTree(){}
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

    SegTree<Node> st(a);

    while(q--){
        int k,x;
        cin>>k>>x;
        st.update(k-1,x);
        cout<<(st.query(0,n-1)).sub<<'\n';
    }
    
    
    return 0;
}
