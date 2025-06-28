#include <bits/stdc++.h>
#define int long long
using namespace std;



class BIT{
    //Fenwick Tree by Fusion15
    vector<int> arr;
    vector<int> tree;
    int n;

    void build(vector<int> &a){
        for(int i=0;i<n;i++){
            add(i,a[i]);
        }
    }

    int query(int ind){
        int s = 0;
        for(int i = ind+1;i>0;i -= i&-i){
            s += tree[i];
        }
        return s;
    }

public:
    BIT(){}

    BIT(int _n){
        n = _n;
        tree.resize(n+1,0);
        arr.resize(n,0);
    }
    
    BIT(vector<int> &a){
        n = a.size();
        arr.resize(n,0);
        tree.resize(n+1,0);
        build(a);
    }

    void add(int ind, int val){
        arr[ind] += val;
        for(int i=ind+1;i<=n; i += i&-i){
            tree[i] += val;
        }
    }

    void update(int ind, int val){
        int diff = val - arr[ind];
        add(ind,diff);
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

    int n,q;
    cin>>n>>q;

    vector<int> a(n);

    for(int &i:a) cin>>i;


    vector<vector<array<int,2>>> queries(n);

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        queries[l].emplace_back(r,i);
    }

    BIT bit(n);


    
    
    return 0;
}
