#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
class SegTree {
    //Template by Fusion15
    vector<T> tree;
    vector<int> arr;
    int n;

    //Change
    T neutralValue = {0,0};
    T merge(T a, T b) {
        return {
            max(a.first,a.second+b.first),
            a.second + b.second
        };
    }

    void build(int node, int start, int end) {
        if(start == end) tree[node] = {max(0ll,arr[start]),arr[start]};
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
            tree[node] = {max(0ll,value),value};
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

    T query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return neutralValue;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        T l = query(2*node, start, mid, L, R);
        T r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

public:
    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4 * n,neutralValue);
        arr = a;
        build(1, 0, n - 1);
    }

    T query(int l, int r) {
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

    int n,q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    SegTree<pair<int,int>> st(a);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int k,u;
            cin>>k>>u;
            k--;
            st.update(k,u);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            auto [res,_] = st.query(l,r);
            cout<<res<<'\n';
        }
    }
    
    
    return 0;
}
