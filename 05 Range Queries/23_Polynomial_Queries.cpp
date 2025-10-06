#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> tree;
vector<pair<ll, ll>> lazy;

ll sumrange(ll start, ll len, ll jump){
    return len * start + jump * (len - 1) * len / 2;
}

ll neutral = 0;
ll merge(ll a, ll b){
    return a + b;
}

pair<ll, ll> pmerge(pair<ll, ll> p1, pair<ll, ll> p2){
    return {p1.first + p2.first, p1.second + p2.second};
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
    if(lazy[node].first != 0){
        int mid = (start + end) / 2;
        int l1 = (mid - start + 1);
        int l2 = (end - mid);

        tree[2 * node] += sumrange(lazy[node].first, l1, lazy[node].second);
        tree[2 * node + 1] += sumrange(lazy[node].first + l1 * lazy[node].second, l2, lazy[node].second);

        lazy[2 * node] = pmerge(lazy[2 * node], lazy[node]);
        lazy[2 * node + 1] = pmerge(lazy[2 * node + 1], {lazy[node].first + l1 * lazy[node].second, lazy[node].second});

        lazy[node] = {0, 0};
    }
}

void increase(int node, int start, int end, int L, int R, int val){
    if(start > R || end < L) return;
    if(start >= L && end <= R){
        tree[node] += sumrange(val, end - start + 1, 1);
        lazy[node] = pmerge(lazy[node], {val, 1});
        return;
    }
    push(node, start, end);
    int mid = (start + end) / 2;
    increase(2 * node, start, mid, L, R, val);
    int left = max(0, min(mid, R) - max(start, L) + 1);
    increase(2 * node + 1, mid + 1, end, L, R, val + left);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

ll query(int node, int start, int end, int L, int R){
    if(start > R || end < L) return neutral;
    if(start >= L && end <= R) return tree[node];
    push(node, start, end);
    int mid = (start + end) / 2;
    ll l = query(2 * node, start, mid, L, R);
    ll r = query(2 * node + 1, mid + 1, end, L, R);
    return merge(l, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    tree.assign(4 * n, 0);
    lazy.assign(4 * n, {0, 0});

    vector<int> a(n);
    for(int &i:a) cin>>i;

    build(1, 0, n - 1, a);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int l, r;
            cin>>l>>r;
            l--, r--;
            increase(1, 0, n - 1, l, r, 1);
        }
        else{
            int l, r;
            cin>>l>>r;
            l--, r--;
            cout<<query(1, 0, n - 1, l, r)<<'\n';
        }
    }
    
    return 0;
}
