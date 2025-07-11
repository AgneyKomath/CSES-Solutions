#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    // Coordinate Compression
    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int &i:a) i = lower_bound(b.begin(), b.end(), i) - b.begin()+1;

    int sz = b.size() + 1;
    
    // Fenwick Tree
    vector<int> tree(sz+1, 0);
    auto add = [&](int ind, int val){
        for(int i = ind+1; i<=sz;i += i&-i){
            tree[i] = (tree[i] + val) % mod;
        }
    };
    auto sum = [&](int ind){
        int res = 0;
        for(int i = ind+1; i; i -= i&-i){
            res = (res + tree[i]) % mod;
        }
        return res;
    };

    for(int i:a){
        int v = sum(i-1);
        add(i, v+1);
    }
    cout<<sum(sz-1);
    
    return 0;
}
