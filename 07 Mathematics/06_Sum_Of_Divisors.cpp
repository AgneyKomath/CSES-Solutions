#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// n(n+1)/2
int sum(long long n){
    long long v1 = n;
    long long v2 = n + 1;

    if(v1%2==0) v1 /= 2;
    else v2/=2;

    v1 %= mod;
    v2 %= mod;

    return 1ll * v1 * v2 % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin>>n;

    int res = 0;
    for(long long i = 1; i*i<=n; i++){
        long long v = n / i;

        int t1 = (v-i) * i % mod;
        int t2 = sum(v);
        int t3 = sum(i-1);
        int t = (0ll + t1 + t2 - t3 + mod) % mod;

        res = (res + t) % mod;
    }

    cout<<res;
    
    return 0;
}
