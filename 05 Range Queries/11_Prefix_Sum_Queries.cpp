#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long subSum = 0;
    long long maxPref = 0;
    Node(){}
    Node(int val){
        subSum = val;
        maxPref = max(0, val);
    }
    Node(long long sum, long long mx){
        subSum = sum;
        maxPref = mx;
    }
};

template <typename T>
class SegTree {
    //Segment tree by Fusion15
    vector<T> tree;
    vector<int> arr;
    int n;

    //Change
    T neutral = Node();
    T merge(T a, T b) {
        return Node(a.subSum + b.subSum, max(a.maxPref, a.subSum + b.maxPref));
    }

    void build(int node, int start, int end) {
        if(start == end){
            //Change 
            tree[node] = Node(arr[start]);
        }
        else{
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid + 1, end);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if(start == end) {
            //Change
            arr[idx] = value;
            tree[node] = Node(value);
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

    T query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return neutral;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        T l = query(2*node, start, mid, L, R);
        T r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

public:
    SegTree(int _n){
        n = _n;
        tree.resize(4*n, neutral);
        arr.resize(n, neutral);
    }
    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4*n, neutral);
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    SegTree<Node> st(a);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int id, v;
            cin>>id>>v;
            id--;
            st.update(id, v);
        }
        else if(t==2){
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            cout<<st.query(l, r).maxPref<<'\n';
        }
    } 
    
    return 0;
}
