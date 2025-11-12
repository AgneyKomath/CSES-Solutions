#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    //Segment Tree by Fusion15
    vector<int> tree;
    int n;

    //Change
    int neutral = 1e9;
    int merge(int a, int b){
        return min(a, b);
    }

    SegTree(vector<int> & a){
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

    vector<array<int, 3>> quers(q);
    for(auto &[t, x, y] : quers){
        cin>>t>>x>>y;
        if(t == 1) x--;
        else x--, y--;
    }

    vector<int> b(a);
    for(auto [t, x, y] : quers){
        if(t == 1) b.push_back(y);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto compress = [&](int v){
        return lower_bound(b.begin(), b.end(), v) - b.begin();
    };
    int sz = b.size();

    vector<int> nxt(n, n);
    vector<set<int>> pos(sz);
    for(int i = 0; i < n; i++){
        a[i] = compress(a[i]);
        if(!pos[a[i]].empty()) nxt[*pos[a[i]].rbegin()] = i;
        pos[a[i]].insert(i);
    }
    for(int i = 0; i < sz; i++){
        if(!pos[i].empty()) nxt[*pos[i].rbegin()] = n;
        pos[i].insert(n);
    }

    SegTree st(nxt);

    auto remove = [&](int id){
        int v = a[id];
        pos[v].erase(id);
        auto next = pos[v].lower_bound(id);
        if(next != pos[v].begin()){
            auto prev = next;
            prev--;
            st.update(*prev, *next);
        }
    };

    auto add = [&](int id){
        int v = a[id];
        auto next = pos[v].lower_bound(id);
        st.update(id, *next);
        if(next != pos[v].begin()){
            auto prev = next;
            prev--;
            st.update(*prev, id);
        }
        pos[v].insert(id);
    };

    for(auto [t, x, y] : quers){
        if(t == 1){
            remove(x);
            y = compress(y);
            a[x] = y;
            add(x);
        }
        else{
            int v = st.query(x, y);
            cout<<(v <= y ? "NO" : "YES")<<'\n';
        }
    }

    return 0;
}
