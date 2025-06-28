#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegTree {
    //Template by Fusion15
    vector<int> tree;
    vector<int> arr;
    int n;

    //Change
    int neutralValue = 0;
    int merge(int a, int b) {
        return a + b;
    }

    void build(int node, int start, int end) {
        if(start == end) tree[node] = arr[start];
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
            tree[node] = value;
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

    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return neutralValue;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int l = query(2*node, start, mid, L, R);
        int r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

    int walk(int node, int start, int end, int pos){
        if(start==end){
            return start;
        }
        int mid = (start + end)/2;
        if(tree[2*node]>=pos){
            return walk(2*node,start,mid,pos);
        }
        else{
            pos -= tree[2*node];
            return walk(2*node+1,mid+1,end,pos);
        }
    }

public:
    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4 * n);
        arr = a;
        build(1, 0, n - 1);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    int walk(int pos){
        if(tree[1]<pos) return -1;
        return walk(1, 0, n-1, pos);
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<int> temp(n,1);
    SegTree st(temp);

    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;
        int ind = st.walk(pos);
        // cout<<ind<<'\n';
        cout<<a[ind]<<' ';
        st.update(ind,0);
    }
    
    
    return 0;
}
