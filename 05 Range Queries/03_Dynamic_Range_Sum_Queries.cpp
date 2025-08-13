#include <bits/stdc++.h>
using namespace std;

struct BIT{
    //Fenwick Tree by Fusion15
    vector<int> arr;
    vector<long long> tree;
    int n;
    
    void build(vector<int> &a){
        for(int i = 0; i<n; i++){
            add(i, a[i]);
        }
    }
    
    BIT(int _n){
        n = _n;
        tree.resize(n+1, 0);
        arr.resize(n, 0);
    }
    
    BIT(vector<int> &a){
        n = a.size();
        arr.resize(n, 0);
        tree.resize(n+1, 0);
        build(a);
    }
    
    void add(int ind, int val){
        arr[ind] += val;
        for(int i=ind+1; i<=n; i += i&-i){
            tree[i] += val;
        }
    }
    
    void update(int ind, int val){
        int diff = val - arr[ind];
        add(ind, diff);
    }
    
    long long query(int ind){
        long long sum = 0;
        for(int i = ind+1; i>0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }

    long long query(int l, int r){
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    BIT bit(a);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int id, val;
            cin>>id>>val;
            id--;
            bit.update(id, val);
        }
        else if(type==2){
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            cout<<bit.query(l, r)<<'\n';
        }
    }
    
    return 0;
}
