#include <bits/stdc++.h>
using namespace std;

vector<long long> tree, ladd, lset;

long long neutral = 0;

long long merge(long long a, long long b){
    return a + b;
}

void build(int node, int start, int end, vector<int> & a){
    if(start == end) tree[node] = a[start];
    else{
        int mid = (start + end) / 2;
        build(2 * node, start, mid, a);
        build(2 * node + 1, mid + 1, end, a);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

void push(int node, int start, int end){
    int mid = (start + end) / 2;
    if(lset[node] != -1){
        lset[2 * node] = lset[2 * node + 1] = lset[node];
        ladd[2 * node] = ladd[2 * node + 1] = 0;
        tree[2 * node] = lset[node] * (mid - start + 1);
        tree[2 * node + 1] = lset[node] * (end - mid);
        lset[node] = -1;
    }
    if(ladd[node] != 0){
        ladd[2 * node] += ladd[node];
        ladd[2 * node + 1] += ladd[node];
        tree[2 * node] += ladd[node] * (mid - start + 1);
        tree[2 * node + 1] += ladd[node] * (end - mid);
        ladd[node] = 0;
    }
}

void addValue(int node, int start, int end, int L, int R, int val){
    if(start > R || end < L) return;
    if(start >= L && end <= R){
        tree[node] += 1ll * val * (end - start + 1);
        ladd[node] += val;
        return;
    }
    push(node, start, end);
    int mid = (start + end) / 2;
    addValue(2 * node, start, mid, L, R, val);
    addValue(2 * node + 1, mid + 1, end, L, R, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void setValue(int node, int start, int end, int L, int R, int val){
    if(start > R || end < L) return;
    if(start >= L && end <= R){
        tree[node] = 1ll * val * (end - start + 1);
        ladd[node] = 0;
        lset[node] = val;
        return;
    }
    push(node, start, end);
    int mid = (start + end) / 2;
    setValue(2 * node, start, mid, L, R, val);
    setValue(2 * node + 1, mid + 1, end, L, R, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

long long query(int node, int start, int end, int L, int R){
    if(start > R || end < L) return neutral;
    if(start >= L && end <= R) return tree[node];
    push(node, start, end);
    int mid = (start + end) / 2;
    long long l = query(2 * node, start, mid, L, R);
    long long r = query(2 * node + 1, mid + 1, end, L, R);
    return merge(l, r);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    tree.assign(4 * n, 0);
    ladd.assign(4 * n, 0);
    lset.assign(4 * n, -1);

    vector<int> a(n);
    for(int &i:a) cin>>i;

    build(1, 0, n - 1, a);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int l, r, x;
            cin>>l>>r>>x;
            addValue(1, 0, n - 1, l - 1, r - 1, x);
        }
        else if(t == 2){
            int l, r, x;
            cin>>l>>r>>x;
            setValue(1, 0, n - 1, l - 1, r - 1, x);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<query(1, 0, n - 1, l - 1, r - 1)<<'\n';
        }
    }
    
    return 0;
}
