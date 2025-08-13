#include <bits/stdc++.h>
using namespace std;

struct BIT{
    //Fenwick Tree by Fusion15
    vector<long long> tree;
    int n;
    
    BIT(int _n){
        n = _n;
        tree.resize(n+1, 0);
    }
    
    void add(int ind, int val){
        for(int i=ind+1; i<=n; i += i&-i){
            tree[i] += val;
        }
    }
    
    long long query(int ind){
        long long sum = 0;
        for(int i = ind+1; i>0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    BIT bit(n+1);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l, r, v;
            cin>>l>>r>>v;
            bit.add(l-1, v);
            bit.add(r, -v);
        }
        else if(type==2){
            int k;
            cin>>k;
            k--;
            long long res = bit.query(k) + a[k];
            cout<<res<<'\n';
        }
    }
    
    return 0;
}
