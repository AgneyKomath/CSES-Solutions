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

    SegTree(){
        n = 0;
    }

    SegTree(int _n){
        n = _n;
        tree.resize(4 * n, neutral);
        a.resize(n, neutral);
    }

    SegTree(vector<int> &arr){
        a = arr;
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int node, int start, int end){
        if(start == end) tree[node] = a[start];
        else{
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int id, int val){
        if(start == end){
            a[id] = val;
            tree[node] = val;
        }
        else{
            int mid = (start + end) / 2;
            if(id <= mid){
                update(2 * node, start, mid, id, val);
            }
            else{
                update(2 * node + 1, mid + 1, end, id, val);
            }
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

    SegTree st(a);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int id, val;
            cin>>id>>val;
            id--;
            st.update(id, val);
        }
        else{
            int l, r;
            cin>>l>>r;
            l--, r--;
            cout<<st.query(l, r)<<'\n';
        }
    }

    return 0;
}
