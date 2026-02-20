#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    
    // Iterative Solution
    ll res = 0;
    while(n){
        int msb = __lg(n);
        ll p = 1ll << msb;
        res += msb * (p >> 1);
        res += n - p + 1;
        n ^= p;
    }
    cout<<res;

    // // Recursive Solution
    // unordered_map<ll, ll> dp;
    // dp[0] = 0;
    // auto rec = [&](ll v, auto &&rec)->ll{
    //     if(dp.count(v)) return dp[v];
    //     int msb = __lg(v);
    //     ll p = 1ll << msb;
    //     return dp[v] = rec(p - 1, rec) + (v - p + 1) + rec(v - p, rec);
    // };
    // cout<<rec(n, rec);

    return 0;
}