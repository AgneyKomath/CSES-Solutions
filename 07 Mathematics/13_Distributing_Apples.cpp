#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int power(int a, int b){
    int res = 1;
    for(; b; b /= 2, a = 1ll * a * a % mod){
        if(b & 1) res = 1ll * res * a % mod;
    }
    return res;
}

int divide(long long a, long long b){
    return a * power(b, mod - 2) % mod;
}

int nCr(int n, int r){
    long long num = 1, den = 1;
    for(int i = 1; i<=min(n - r, r); i++){
        num = num * (n - i + 1) % mod;
        den = den * i % mod;
    }
    return divide(num, den);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    // answer is stars and bars n + m - 1 choose n - 1
    cout<<nCr(n + m - 1, n - 1);

    // long long num = 1, den = 1;
    // for(int i = 1; i<=min(m, n-1); i++){
    //     num = num * (n + m - i) % mod;
    //     den = den * i % mod;
    // }
    // int inv = 1;
    // for(int b = mod - 2; b; b /= 2, den = den * den % mod){
    //     if(b & 1) inv = inv * den % mod;
    // }
    // cout<< num * inv % mod;

    
    return 0;
}
