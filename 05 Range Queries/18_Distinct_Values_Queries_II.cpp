#include <bits/stdc++.h>
using namespace std;

struct SegTreeMax {
    //Segment Tree by Fusion15
    vector<int> tree;
    vector<int> arr;
    int n;

    //Change
    int neutral = -1e9;
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

    void update(int node, int start, int end, int idx, int value) {
        if(start == end) {
            arr[idx] = value;
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

    SegTreeMax(const vector<int> &a) {
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

struct SegTreeMin {
    //Segment Tree by Fusion15
    vector<int> tree;
    vector<int> arr;
    int n;

    //Change
    int neutral = 1e9;
    int merge(int a, int b) {
        return min(a, b);
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

    SegTreeMin(const vector<int> &a) {
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<array<int, 3>> queries(q);
    for(auto &[x, y, z]:queries){
        cin>>x>>y>>z;
        y--;
        if(x==2) z--;
    }
    
    // Coordinate Compression
    vector<int> b(a);
    for(auto [x, y, z]:queries) if(x==1) b.push_back(z);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto compress = [&](int v){return lower_bound(b.begin(), b.end(), v) - b.begin();};
    int sz = b.size();

    // set of current indices for each value to enable binary search
    vector<set<int>> mp(sz);
    for(int i = 0; i<sz; i++){
        mp[i].insert(-1);
        mp[i].insert(n);
    }

    for(int i = 0; i<n; i++){
        a[i] = compress(a[i]);
        mp[a[i]].insert(i);
    }

    // first left and right indices containing same value
    vector<int> left(n, -1), right(n, n);
    for(int i = 0; i<n; i++){
        auto itr = mp[a[i]].upper_bound(i);
        right[i] = *(itr--);
        left[i] = *(--itr);
    }
    
    SegTreeMax stl(left);
    SegTreeMin str(right);

    auto remove = [&](int pos, int val){
        mp[val].erase(pos);
        auto itr = mp[val].upper_bound(pos);
        int right = *itr;
        int left = *(--itr);
        if(right != n) stl.update(right, left);
        if(left != -1) str.update(left, right);
    };

    auto add = [&](int pos, int val){
        auto itr = mp[val].upper_bound(pos);
        int right = *itr;
        int left = *(--itr);
        str.update(pos, right);
        stl.update(pos, left);
        if(right != n) stl.update(right, pos);
        if(left != -1) str.update(left, pos);
        mp[val].insert(pos);
    };

    for(auto [t, y, z]:queries){
        if(t==1){
            z = compress(z);
            remove(y, a[y]);
            add(y, z);
            a[y] = z; 
        }
        else{
            // if max left index and min right index lie outside [y, z] all values are distinct
            int mx = stl.query(y, z);
            int mn = str.query(y, z);
            if(mx<y && mn>z) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    
    return 0;
}
