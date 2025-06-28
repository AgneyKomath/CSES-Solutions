#include <bits/stdc++.h>
#define int long long
using namespace std;

class LazySegTree{
    vector<int> tree, lazy;
    int n;

    void build(int node, int start, int end, vector<int> &a){
        if(start==end) tree[node] = a[start];
        else{
            int mid = (start+end)/2;
            build(2*node, start, mid, a);
            build(2*node+1, mid+1, end, a);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    void apply(int node, int len, int add){
        tree[node] += add*len;
        lazy[node] += add;
    }

    void push(int node, int start, int end){
        int mid = (start+end)/2;
        apply(2*node, mid-start+1, lazy[node]);
        apply(2*node+1, end-mid, lazy[node]);
        lazy[node] = 0;
    };

    void update(int node, int start, int end, int L, int R, int add){
        if(R<start || L>end) return ;
        if(R>=start && L<=end){
            apply(node, end-start+1, add);
        }
        else{
            push(node, start, end);
            int mid = (start+end)/2;
            update(2*node, start, mid, L, R, add);
            update(2*node+1, mid+1, end, L, R, add);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    int query(int node, int start, int end, int L, int R){
        if(R<start || L>end) return 0;
        if(R>=end && L<=start) return tree[node];
        push(node, start, end);
        int mid = (start+end)/2;
        int l = query(2*node, start, mid, L, R);
        int r = query(2*node+1, mid+1, end, L, R);
        return l+r;
    }

public:
    LazySegTree(vector<int> &a){
        n = a.size();
        tree.resize(4*n, 0);
        lazy.resize(4*n, 0);

        build(1, 0, n-1, a);
    }

};


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    LazySegTree lst(a);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            
        }
    }
    
    
    return 0;
}
