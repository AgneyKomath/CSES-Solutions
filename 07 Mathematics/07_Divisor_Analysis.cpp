#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b){
    long long res = 1;
    for(; b; b /= 2, a = a * a % mod){
        if(b & 1) res = res * a % mod;
    }
    return res;
}

long long mdiv(long long a, long long b){
    long long d = power(b, mod - 2);
    return a * d % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<long long> p(n), k(n);

    for(int i = 0; i<n; i++){
        cin>>p[i]>>k[i];
    }

    long long ndiv = 1, pdiv = 1, sdiv = 1, ndp = 1;
    for(int i = 0; i<n; i++){

        // power has to be taken mod - 1
        long long e = ((k[i] * (k[i] + 1) / 2) % (mod - 1)) * ndp % (mod - 1);
        long long x = power(p[i], e);
        pdiv = x * power(pdiv, k[i] + 1) % mod;

        ndiv = ndiv * (k[i] + 1) % mod;
        ndp = ndp * (k[i] + 1) % (mod - 1);

        int num = (power(p[i], k[i] + 1) - 1 + mod) % mod;
        sdiv = sdiv * mdiv(num, p[i] - 1) % mod;
    }

    cout<<ndiv<<' '<<sdiv<<' '<<pdiv;
    
    return 0;
}
