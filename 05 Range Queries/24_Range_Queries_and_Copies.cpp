#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node{
    ll val = 0;
    Node *l = nullptr, *r = nullptr;
    Node(ll x){
        val = x;
    }
    Node(Node *_l, Node *_r){
        l = _l;
        r = _r;
        val = l->val + r->val;
    }
};

Node *build(int start, int end, vector<int> &a){
    if(start == end) return new Node(a[start]);
    int mid = (start + end) / 2;
    Node *l = build(start, mid, a);
    Node *r = build(mid + 1, end, a);
    Node *res = new Node(l, r);
    return res;
}

Node *update(Node *node, int start, int end, int id, int v){
    if(start == end) return new Node(v);
    int mid = (start + end) / 2;
    Node *l = node->l;
    Node *r = node->r;
    if(id <= mid) l = update(node->l, start, mid, id, v);
    else r = update(node->r, mid + 1, end, id, v);
    Node * res = new Node(l, r);
    return res;
}

ll query(Node *node, int start, int end, int L, int R){
    if(start > R || end < L) return 0;
    if(start >= L && end <= R) return node->val;
    int mid = (start + end) / 2;
    ll l = query(node->l, start, mid, L, R);
    ll r = query(node->r, mid + 1, end, L, R);
    return l + r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<Node*> roots;
    roots.push_back(build(0, n - 1, a));

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int k, id, x;
            cin>>k>>id>>x;
            k--, id--;
            roots[k] = update(roots[k], 0, n - 1, id, x);
        }
        else if(t == 2){
            int k, l, r;
            cin>>k>>l>>r;
            k--, l--, r--;
            cout<<query(roots[k], 0, n - 1, l, r)<<'\n';
        }
        else{
            int k;
            cin>>k;
            k--;
            roots.push_back(roots[k]);
        }
    }

    return 0;
}
