#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    //Segment Tree by Fusion15
    vector<int> tree;
    int n;

    //Change
    int neutral = 0;
    int merge(int a, int b) {
        return max(a, b);
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

    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = val;
        }
        else{
            int mid = (start + end) / 2;
            if(idx <= mid) {
                update(2*node, start, mid, idx, val);
            }
            else{
                update(2*node+1, mid + 1, end, idx, val);
            }
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    int walk(int node, int start, int end, int val){
        if(start==end) return start;
        int mid = (start + end) / 2;
        if(tree[2*node]>=val){
            return walk(2*node, start, mid, val);
        }
        else{
            return walk(2*node+1, mid+1, end, val);
        }
    }

    SegTree(vector<int> &a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    
    int walk(int val){
        if(tree[1]<val) return -1;
        return walk(1, 0, n-1, val);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    SegTree st(a);

    while(m--){
        int v;
        cin>>v;
        int id = st.walk(v);
        cout<<id+1<<' ';
        if(id != -1){
            a[id] -= v;
            st.update(id, a[id]);
        }
    }

    
    return 0;
}
