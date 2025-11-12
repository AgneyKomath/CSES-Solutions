#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    //Segment Tree by Fusion15
    vector<int> tree;
    int n;

    //Change
    int neutral = 0;
    int merge(int a, int b){
        return max(a, b);
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

    void subtract(int node, int start, int end, int id, int val){
        if(start == end) tree[node] -= val;
        else{
            int mid = (start + end) / 2;
            if(id <= mid) subtract(2 * node, start, mid, id, val);
            else subtract(2 * node + 1, mid + 1, end, id, val);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int walk(int node, int start, int end, int val){
        if(start == end) return start;
        int mid = (start + end) / 2;
        if(tree[2 * node] >= val) return walk(2 * node, start, mid, val);
        return walk(2 * node + 1, mid + 1, end, val);
    }

    void subtract(int id, int val){
        subtract(1, 0, n - 1, id, val);
    }

    int walk(int v){
        if(tree[1] < v) return -1;
        return walk(1, 0, n - 1, v);
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
        int v;
        cin>>v;
        int id = st.walk(v);
        cout<<id + 1<<' ';
        if(id != -1) st.subtract(id, v);
    }

    return 0;
}
