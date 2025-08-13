#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    //Segment Tree by Fusion15
    vector<int> tree;
    int n;

    //Change
    int neutral = 1e9;
    int merge(int a, int b) {
        return min(a, b);
    }

    void build(int node, int start, int end, vector<int> &arr) {
        if(start == end) tree[node] = arr[start];
        else{
            int mid = (start + end) / 2;
            build(2*node, start, mid, arr);
            build(2*node+1, mid + 1, end, arr);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if(start == end) {
            tree[node] = value;
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

    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return neutral;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int l = query(2*node, start, mid, L, R);
        int r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

    SegTree(int _n){
        n = _n;
        tree.resize(4*n, neutral);
    }

    SegTree(vector<int> &a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    int query(int l, int r) {
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

    SegTree st(a);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int id, val;
            cin>>id>>val;
            id--;
            st.update(id, val);
        }
        else if(type==2){
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            cout<<st.query(l, r)<<'\n';
        }
    }
    
    return 0;
}
