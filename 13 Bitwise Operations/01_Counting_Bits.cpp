#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    
    // Iterative Solution
    long long res = 0;
    while(n){
        int msb = __lg(n);
        long long p = 1ll<<msb;
        res += msb * (1ll<<(msb-1));
        res += (n-p+1);
        n -= p;
    }
    cout<<res;

    // // Recursive Solution
    // unordered_map<long long, long long> dp;
    // dp[0] = 0;
    // auto rec = [&](long long v, auto &&rec)->long long{
    //     if(dp.count(v)) return dp[v];
    //     int msb = __lg(v);
    //     long long p = 1ll<<msb;
    //     return dp[v] = rec(p-1, rec) + (v-p+1) + rec(v-p, rec);
    // };
    // cout<<rec(n, rec);


    
    return 0;
}
