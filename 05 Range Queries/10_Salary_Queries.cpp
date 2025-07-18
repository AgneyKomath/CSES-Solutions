#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegTree {
    //Template by Fusion15
    vector<int> tree;
    vector<int> arr;
    int n;

    //Change
    int neutralValue = 0;
    int merge(int a, int b) {
        return a + b;
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
            arr[idx] += value;
            tree[node] += value;
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
        if (R < start || L > end) return neutralValue;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int l = query(2*node, start, mid, L, R);
        int r = query(2*node+1, mid + 1, end, L, R);
        return merge(l, r);
    }

public:
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

    int n,q;
    cin>>n>>q;

    vector<int> arr(n);
    for(int &i:arr) cin>>i;

    vector<array<int,3>> quer;
    vector<int> srs(arr);

    while(q--){
        char type;
        int a,b;
        cin>>type>>a>>b;
        quer.push_back({type=='?',a,b});
        if(type=='!') srs.push_back(b);
    } 



    sort(srs.begin(),srs.end());
    srs.erase(unique(srs.begin(), srs.end()), srs.end());

    vector<int> temp(srs.size(),0);
    for(auto &i:arr){
        i = lower_bound(srs.begin(),srs.end(),i)-srs.begin();
        temp[i]++;
    }


    SegTree st(temp);

    for(auto [t,a,b]:quer){
        if(t==1){
            a = lower_bound(srs.begin(),srs.end(),a) - srs.begin();
            b = upper_bound(srs.begin(),srs.end(),b) - srs.begin()-1;
            cout<<st.query(a,b)<<'\n';
        }
        else{
            a--;
            b = lower_bound(srs.begin(),srs.end(),b) - srs.begin();

            int prev = arr[a];
            arr[a] = b;

            st.update(prev,-1);
            st.update(b,1);
        }
    }


    
    
    return 0;
}
