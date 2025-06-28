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
        return max(a,b);
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

    int walk(int node, int start, int end, int val){
        if(start==end) return start;
        int mid = (start + end)/2;
        if(tree[2*node]>=val){
            return walk(2*node,start,mid,val);
        }
        else{
            return walk(2*node+1,mid+1,end,val);
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

    int walk(int val){
        if(tree[1]<val) return -1;
        return walk(1,0,n-1,val);
    }

};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    SegTree st(a);

    while(m--){
        int num;
        cin>>num;

        int ind = st.walk(num);
        cout<<ind+1<<' ';
        if(ind!=-1){
            a[ind] -= num;
            st.update(ind,a[ind]);
        }
    }
    
    
    return 0;
}
