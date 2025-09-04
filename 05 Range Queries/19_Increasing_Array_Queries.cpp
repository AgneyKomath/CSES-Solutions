#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    //Segment Tree by Fusion15
    vector<int> tree;
    vector<int> arr;
    int n;

    //Change
    int neutral = 0;
    int merge(int a, int b) {
        return max(a, b);
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

    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return neutral;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int l = query(2*node, start, mid, L, R);
        int r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

    int nextGreat(int node, int start, int end, int idx, int val){
        if(end<idx || tree[node]<=val) return n;
        if(start==end) return start;
        int mid = (start + end)/2;
        int l = nextGreat(2*node, start, mid, idx, val);
        if(l!=n) return l;
        return nextGreat(2*node+1, mid+1, end, idx, val);
    };

    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4 * n);
        arr = a;
        build(1, 0, n - 1);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    int nextGreat(int idx, int val){
        return nextGreat(1, 0, n-1, idx, val);
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<long long> pref(n+1, 0);
    for(int i = 0; i<n; i++) pref[i+1] = pref[i] + a[i];
    auto sumQuery = [&](int l, int r){
        if(l>r) return 0ll;
        return pref[r+1] - pref[l];
    };

    SegTree st(a);

    // min cost to make suffix at i increasing
    vector<long long> dp(n+1);
    dp[n] = 0;
    for(int i = n-1; i>=0; i--){
        // This one can be done without Segment Tree using Monotonic Stack 
        int id = st.nextGreat(i, a[i]);
        dp[i] = dp[id] + 1ll * (id - i) * a[i] - sumQuery(i, id-1);
    }
    
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;r--;

        long long res = dp[l];

        int mx = st.query(l, r);
        // first index greater than r that has value greater than mx
        int id = st.nextGreat(r, mx);

        res -= dp[id] + 1ll * (id - r - 1) * mx - sumQuery(r+1, id-1);

        cout<<res<<'\n';
    }  
    
    return 0;
}
