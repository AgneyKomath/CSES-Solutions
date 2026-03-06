#include <bits/stdc++.h>
using namespace std;

struct ShashDynamic{
    using ll = long long;

    struct BIT{
        int n, mod;
        vector<int> tree;
        BIT(){}
        BIT(int n, int mod) : n(n), mod(mod), tree(n + 1, 0){}
        void add(int id, int val){
            if(val < 0) val = (val % mod + mod) % mod;
            for(int i = id + 1; i <= n; i += i & -i){
                tree[i] += val;
                if(tree[i] >= mod) tree[i] -= mod;
            }
        }
        int query(int id){
            int res = 0;
            for(int i = id + 1; i; i -= i & -i){
                res += tree[i];
                if(res >= mod) res -= mod;
            }
            return res;
        }
        int query(int l, int r){
            if(l > r) return 0;
            int res = query(r) - query(l - 1);
            if(res < 0) res += mod;
            return res;
        }
    };

    const int M1 = 1e9 + 7, M2 = 1e9 + 9;

    ll power(ll a, ll b, int mod){
        ll res = 1;
        for(; b; b /= 2, a = a * a % mod){
            if(b & 1) res = res * a % mod;
        }
        return res;
    }

    string s;
    int n, p;
    vector<int> pw1, pw2, ipw1, ipw2;
    BIT bit1, bit2, ibit1, ibit2;

    ShashDynamic(string _s){
        s = _s;
        n = (int)s.size();

        p = 543453436;

        bit1 = BIT(n, M1);
        bit2 = BIT(n, M2);
        ibit1 = BIT(n, M1);
        ibit2 = BIT(n, M2);

        pw1.assign(n + 1, 1);
        pw2.assign(n + 1, 1);
        ipw1.assign(n + 1, 1);
        ipw2.assign(n + 1, 1);

        int p1 = p % M1;
        int p2 = p % M2;
        for(int i = 1; i <= n; i++){
            pw1[i] = (ll)pw1[i - 1] * p1 % M1;
            pw2[i] = (ll)pw2[i - 1] * p2 % M2;
        }

        int ib1 = power(p1, M1 - 2, M1);
        int ib2 = power(p2, M2 - 2, M2);
        for(int i = 1; i <= n; i++){
            ipw1[i] = (ll)ipw1[i - 1] * ib1 % M1;
            ipw2[i] = (ll)ipw2[i - 1] * ib2 % M2;
        }

        for(int i = 0; i < n; i++){
            ll x = (unsigned char)s[i];
            bit1.add(i, x * pw1[i] % M1);
            bit2.add(i, x * pw2[i] % M2);
        }

        for(int i = n - 1; i >= 0; i--){
            ll x = (unsigned char)s[i];
            ibit1.add(i, x * pw1[n - i - 1] % M1);
            ibit2.add(i, x * pw2[n - i - 1] % M2);
        }
    }

    void update(int id, char c){
        ll ov = (unsigned char)s[id];
        s[id] = c;
        ll nv = (unsigned char)s[id];
        int d1 = ((nv * pw1[id] - ov * pw1[id]) % M1 + M1) % M1;
        int d2 = ((nv * pw2[id] - ov * pw2[id]) % M2 + M2) % M2;
        bit1.add(id, d1);
        bit2.add(id, d2);
        int id1 = ((nv * pw1[n - id - 1] - ov * pw1[n - id - 1]) % M1 + M1) % M1;
        int id2 = ((nv * pw2[n - id - 1] - ov * pw2[n - id - 1]) % M2 + M2) % M2;
        ibit1.add(id, id1);
        ibit2.add(id, id2);
    }

    pair<int, int> query(int l, int r){
        int h1 = (ll)bit1.query(l, r) * ipw1[l] % M1;
        int h2 = (ll)bit2.query(l, r) * ipw2[l] % M2;
        return {h1, h2};
    }

    pair<int, int> iquery(int l, int r){
        int h1 = (ll)ibit1.query(l, r) * ipw1[n - r - 1] % M1;
        int h2 = (ll)ibit2.query(l, r) * ipw2[n - r - 1] % M2;
        return {h1, h2};
    }

    bool isPal(int l, int r){
        return query(l, r) == iquery(l, r);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    string s;
    cin>>s;

    ShashDynamic sh(s);

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int id;
            char c;
            cin>>id>>c;
            id--;
            sh.update(id, c);
        }
        else{
            int l, r;
            cin>>l>>r;
            l--, r--;
            cout<<(sh.isPal(l, r) ? "YES" : "NO")<<'\n';
        }
    }

    return 0;
}