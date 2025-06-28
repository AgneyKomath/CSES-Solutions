#include <bits/stdc++.h>
#define int long long
using namespace std;

//Fenwick Tree
class BIT{
    //Fenwick Tree by Fusion15
    vector<int> tree;
    int n;

    int query(int ind){
        int s = 0;
        for(int i = ind+1;i>0;i -= i&-i){
            s += tree[i];
        }
        return s;
    }

public:

    BIT(int _n){
        n = _n;
        tree.resize(n+1,0);
    }

    void add(int ind, int val){
        for(int i=ind+1;i<=n; i += i&-i){
            tree[i] += val;
        }
    }

    int query(int l, int r){
        return query(r) - query(l-1);
    }
};




int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    vector<array<int,3>> a(n);
    vector<int> coords;
    
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        coords.push_back(l);
        coords.push_back(r);
        a[i] = {l,r,i};
    }


    //coordinate compression
    sort(coords.begin(),coords.end());
    coords.erase(unique(coords.begin(),coords.end()),coords.end());
    auto compress= [&](int val){
        return lower_bound(coords.begin(),coords.end(), val) - coords.begin();
    };
    for(int i=0;i<n;i++){
        a[i][0] = compress(a[i][0]);
        a[i][1] = compress(a[i][1]);
    }

    //sort
    sort(a.begin(),a.end(),[](auto &v1, auto &v2){
        if(v1[0]==v2[0]) return v1[1]>v2[1];
        return v1[0]<v2[0];
    });

    
    int sz = coords.size();
    vector<int> contained(n, 0), contains(n, 0);
    BIT bit1(sz), bit2(sz); 

    //How many is a range contained in
    for(int i=0; i<n; i++){
        auto &[l, r, ind] = a[i];
        contained[ind] =  bit1.query(r,sz-1);
        bit1.add(r,1);   
    }

    //How many ranges does it contain
    for(int i=n-1; ~i; i--){
        auto &[l, r, ind] = a[i];
        contains[ind] =  bit2.query(l,r);
        bit2.add(r,1);   
    }


    for(auto i:contains) cout<<i<<' ';
    cout<<'\n';
    for(auto i:contained) cout<<i<<' ';
    cout<<'\n';
    
    
    return 0;
}



// // Segment Tree
// class SegTree {
//     //Segment Tree by Fusion15
//     vector<int> tree;
//     int n;

//     //Change
//     int neutral = 0;
//     int merge(int a, int b) {
//         return a+b;
//     }

//     void update(int node, int start, int end, int idx) {
//         if(start == end) {
//             tree[node]++;
//         }
//         else{
//             int mid = (start + end) / 2;
//             if(start <= idx && idx <= mid) {
//                 update(2*node, start, mid, idx);
//             }
//             else{
//                 update(2*node+1, mid + 1, end, idx);
//             }
//             tree[node] = merge(tree[2*node], tree[2*node+1]);
//         }
//     }

//     int query(int node, int start, int end, int L, int R) {
//         if (R < start || L > end) return neutral;
//         if (L <= start && end <= R) return tree[node];
//         int mid = (start + end) / 2;
//         int l = query(2*node, start, mid, L, R);
//         int r = query(2*node+1, mid + 1, end, L, R);
//         return merge(l, r);
//     }

// public:

//     SegTree(int _n){
//         n = _n;
//         tree.resize(4*n);
//     }

//     int query(int l, int r) {
//         return query(1, 0, n - 1, l, r);
//     }

//     void update(int idx) {
//         update(1, 0, n - 1, idx);
//     }
// };




// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n;
//     cin>>n;

//     vector<array<int,3>> a(n);
//     vector<int> coords;
    
//     for(int i=0;i<n;i++){
//         int l,r;
//         cin>>l>>r;
//         coords.push_back(l);
//         coords.push_back(r);
//         a[i] = {l,r,i};
//     }


//     //coordinate compression
//     sort(coords.begin(),coords.end());
//     coords.erase(unique(coords.begin(),coords.end()),coords.end());
//     auto compress= [&](int val){
//         return lower_bound(coords.begin(),coords.end(), val) - coords.begin();
//     };
//     for(int i=0;i<n;i++){
//         a[i][0] = compress(a[i][0]);
//         a[i][1] = compress(a[i][1]);
//     }

//     //sort
//     sort(a.begin(),a.end(),[](auto &v1, auto &v2){
//         if(v1[0]==v2[0]) return v1[1]>v2[1];
//         return v1[0]<v2[0];
//     });

    
//     int sz = coords.size();
//     vector<int> contained(n, 0), contains(n, 0);
//     SegTree st1(sz), st2(sz); 

//     //How many is a range contained in
//     for(int i=0; i<n; i++){
//         auto &[l, r, ind] = a[i];
//         contained[ind] =  st1.query(r,sz-1);
//         st1.update(r);   
//     }

//     //How many ranges does it contain
//     for(int i=n-1; ~i; i--){
//         auto &[l, r, ind] = a[i];
//         contains[ind] =  st2.query(l,r);
//         st2.update(r);   
//     }


//     for(auto i:contains) cout<<i<<' ';
//     cout<<'\n';
//     for(auto i:contained) cout<<i<<' ';
//     cout<<'\n';
    
    
//     return 0;
// }
