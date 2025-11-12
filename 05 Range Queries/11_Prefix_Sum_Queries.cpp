#include <bits/stdc++.h>
using namespace std;

template <class T, T (*merge)(T, T), T (*neutral)()>
struct SegTree{
    //Segment Tree by Fusion15
    vector<T> tree;
    int n;

    SegTree(){
        n = 0;
    }

    SegTree(int _n){
        n = _n;
        tree.resize(4 * n, neutral());
    }

    SegTree(vector<T> &a){
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int node, int start, int end, vector<T> &a){
        if(start == end) tree[node] = a[start];
        else{
            int mid = (start + end) / 2;
            build(2 * node, start, mid, a);
            build(2 * node + 1, mid + 1, end, a);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int id, T val){
        if(start == end) tree[node] = val;
        else{
            int mid = (start + end) / 2;
            if(id <= mid) update(2 * node, start, mid, id, val);
            else update(2 * node + 1, mid + 1, end, id, val);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    T query(int node, int start, int end, int L, int R){
        if (R < start || L > end) return neutral();
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        T l = query(2 * node, start, mid, L, R);
        T r = query(2 * node + 1, mid + 1, end, L, R);
        return merge(l, r);
    }

    T query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }

    void update(int id, T val){
        update(1, 0, n - 1, id, val);
    }
};

struct Node{
    long long mxpref = 0;
    long long full = 0;
    Node(){}
    Node(int val){
        full = val;
        mxpref = max(0, val);
    }
};

Node merge(Node a, Node b){
    Node res;
    res.mxpref = max(a.mxpref, a.full + b.mxpref);
    res.full = a.full + b.full;
    return res;
}

Node neutral(){
    return Node();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<Node> a(n);
    for(int i = 0; i < n; i++){
        int v;
        cin>>v;
        a[i] = Node(v);
    }

    SegTree<Node, merge, neutral> st(a);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int id, v;
            cin>>id>>v;
            id--;
            st.update(id, Node(v));
        }
        else{
            int l, r;
            cin>>l>>r;
            l--, r--;
            Node res = st.query(l, r);
            cout<<res.mxpref<<'\n';
        }
    }

    return 0;
}
