#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

struct LiChaoTreeVectorMin{
    struct Line{
        ll m, b;
        Line(ll _m = 0, ll _b = 0){
            m = _m, b = _b;
        }
        ll f(ll x){
            return m * x + b;
        }
    };

    int n;
    vector<Line> p;
    vector<ll> xs;

    LiChaoTreeVectorMin(vector<int> x){
        n = 1 << (__lg((int)x.size()) + 1);
        p.assign(n * 2, {0, INF});
        sort(x.begin(), x.end());
        while(x.size() < n) x.push_back(x.back());
        xs.assign(n * 2, 0);
        for(int i = 0; i < n; i++) xs[i + n] = x[i];
        for(int i = n - 1; i > 0; i--){
            xs[i] = xs[i * 2];
        }
    }

    void insert(Line l){
        int s = 1;
        while(s < n){
            ll p1 = xs[s * 2], p2 = xs[s * 2 + 1];
            bool c1 = l.f(p1) < p[s].f(p1);
            bool c2 = l.f(p2) < p[s].f(p2);
            if(c2) swap(l, p[s]);
            s = 2 * s + (c1 == c2);
        }
        if(l.f(xs[s]) < p[s].f(xs[s])){
            p[s] = l;
        }
    }

    ll query(ll x){
        int i = lower_bound(xs.begin() + n, xs.end(), x) - xs.begin();
        ll r = INF;
        while(i > 0){
            r = min(r, p[i].f(x));
            i /= 2;
        }
        return r;
    }
};

struct LiChaoTreeMin{
    struct Line{
        ll m, b;
        Line(ll _m = 0, ll _b = 0){
            m = _m, b = _b;
        }
        ll f(ll x){
            return m * x + b;
        }
    };
 
    vector<int> vis;
    vector<Line> p;
    int n;
 
    LiChaoTreeMin(int _n){
        n = _n;
        vis.resize(2 * n, 0);
        p.resize(2 * n);
    }
 
    void insert(int x, int l, int r, Line v){
        if(!vis[x]){
            vis[x] = 1;
            p[x] = v;
            return;
        }
        if(p[x].f(l) <= v.f(l) && p[x].f(r) <= v.f(r)) return;
        if(p[x].f(l) >= v.f(l) && p[x].f(r) >= v.f(r)){
            p[x] = v;
            return;
        }
        
        int m = (l + r) / 2;
 
        if(p[x].f(l) > v.f(l)) swap(p[x], v);
 
        if(p[x].f(m) <= v.f(m)) insert(2 * x + 1, m + 1, r, v);
        else{
            swap(p[x], v);
            insert(2 * x, l, m, v);
        }
    }
 
    ll query(int x, int l, int r, int pos){
        if(!vis[x]) return INF;
        if(l == r) return p[x].f(l);
        int m = (l + r) / 2;
        ll res = p[x].f(pos);
        if(pos <= m) res = min(res, query(2 * x, l, m, pos));
        else res = min(res, query(2 * x + 1, m + 1, r, pos));
        return res;
    }
 
    void insert(ll m, ll b){
        Line v(m, b);
        insert(1, 1, n, v);
    }
 
    ll query(int pos){
        return query(1, 1, n, pos);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> s(n), f(n);
    for(int &i : s) cin>>i;
    for(int &i : f) cin>>i;

    LiChaoTreeMin cht(1e6 + 1);
    cht.insert(x, 0);
    for(int i = 0; i < n - 1; i++){
        ll val = cht.query(s[i]);
        cht.insert(f[i], val);
    }

    ll res = cht.query(s[n - 1]);
    cout<<res;

    // LiChaoTreeVectorMin cht(s);
    // cht.insert({x, 0});

    // for(int i = 0; i < n - 1; i++){
    //     ll val = cht.query(s[i]);
    //     cht.insert({f[i], val});
    // }

    // ll res = cht.query(s[n - 1]);
    // cout<<res;

    return 0;
}