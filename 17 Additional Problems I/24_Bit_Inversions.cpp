#include <bits/stdc++.h>
using namespace std;

struct Node{
    int p[2]{};
    int s[2]{};
    int mx = 0;
    int len = 0;

    Node(){}

    Node(char c){
        p[c - '0'] = s[c - '0'] = mx = len = 1;
    }

    friend Node operator+(const Node &a, const Node &b){
        Node res;
        for(int i = 0; i < 2; i++){
            res.p[i] = a.p[i] + (a.p[i] == a.len ? b.p[i] : 0);
            res.s[i] = b.s[i] + (b.s[i] == b.len ? a.s[i] : 0); 
        }
        res.mx = max({a.mx, b.mx, res.p[0], res.p[1], res.s[0], res.s[1], a.s[0] + b.p[0], a.s[1] + b.p[1]});
        res.len = a.len + b.len;
        return res;
    }
};

struct SegTree {
    //Segment Tree by Fusion15
    vector<Node> tree;
    int n;

    SegTree(string &s){
        n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void build(int node, int start, int end, string &s){
        if(start == end) tree[node] = s[start];
        else{
            int mid = (start + end) / 2;
            build(2 * node, start, mid, s);
            build(2 * node + 1, mid + 1, end, s);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int id, char val){
        if(start == end) tree[node] = val;
        else{
            int mid = (start + end) / 2;
            if(id <= mid) update(2 * node, start, mid, id, val);
            else update(2 * node + 1, mid + 1, end, id, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int id, int val){
        update(1, 0, n - 1, id, val);
    }

    int query(){
        return tree[1].mx;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    SegTree st(s);

    int q;
    cin>>q;
    while(q--){
        int id;
        cin>>id;
        id--;
        char op = '1' + '0' - s[id];
        st.update(id, op);
        s[id] = op;
        cout<<st.query()<<' ';
    }

    return 0;
}