#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegTree {
    //Segment Tree by Fusion15
    vector<int> tree;
    vector<int> arr;
    int n;

    //Change
    int neutral = 0;
    int merge(int a, int b) {
        return a+b;
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
        if (R < start || L > end) return neutral;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int l = query(2*node, start, mid, L, R);
        int r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

public:
    SegTree() {}
    SegTree(int _n){
        n = _n;
        tree.resize(4*n, neutral);
        arr.resize(n, neutral);
    }
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

    vector<int> c(n);
    for(int &i:c) cin>>i;

    vector<vector<int>> adj(n);
    for(int i =0 ;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Euler Tour
    vector<int> a;
    vector<pair<int,int>> mp(n);
    auto rec = [&](int node, int prev, auto &&self)->void{
        {}
        a.push_back(c[node]);
        mp[node].first = a.size()-1;
        for(int i:adj[node]){
            if(i==prev) continue;
            self(i, node, self);
        }
        mp[node].second = a.size()-1;
    };
    rec(0, -1, rec);

    SegTree st(a);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int s, x;
            cin>>s>>x;
            int ind = mp[s-1].first;
            st.update(ind, x);
        }
        else{
            int s;
            cin>>s;
            int l = mp[s-1].first;
            int r = mp[s-1].second;
            cout<<st.query(l, r)<<'\n';
        }
    }
    
    return 0;
}


