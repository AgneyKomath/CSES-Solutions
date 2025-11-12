#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    //Segment Tree by Fusion15
    vector<int> tree, a;
    int n;

    //Change
    int neutral = 1e9;
    int merge(int a, int b){
        return min(a, b);
    }

    SegTree(vector<int> &a){
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int node, int start, int end, vector<int> &a){
        if(start == end) tree[node] = a[start];
        else{
            int mid = (start + end) / 2;
            build(2 * node, start, mid, a);
            build(2 * node + 1, mid + 1, end, a);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int id, int val){
        if(start == end) tree[node] = val;
        else{
            int mid = (start + end) / 2;
            if(id <= mid) update(2 * node, start, mid, id, val);
            else update(2 * node + 1, mid + 1, end, id, val);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int L, int R){
        if (R < start || L > end) return neutral;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int l = query(2 * node, start, mid, L, R);
        int r = query(2 * node + 1, mid + 1, end, L, R);
        return merge(l, r);
    }

    void update(int id, int val){
        update(1, 0, n - 1, id, val);
    }

    int query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> ll(a), rr(a);
    for(int i = 0; i < n; i++){
        ll[i] += n - i - 1;
        rr[i] += i;
    }

    SegTree left(ll), right(rr);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int id, v;
            cin>>id>>v;
            id--;
            left.update(id, v + n - id - 1);
            right.update(id, v + id);
        }
        else{
            int id;
            cin>>id;
            id--;
            int lv = left.query(0, id) - (n - id - 1);
            int rv = right.query(id, n - 1) - id;
            cout<<min(lv, rv)<<'\n';
        }
    }

    return 0;
}
