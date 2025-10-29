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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    if(n & 1){
        cout<<0;
        return 0;
    }

    n /= 2;

    // Nth Catalan Number
    // 2nCn / (n + 1);

    long long num = 1;
    for(int i = n + 2; i <= 2 * n; i++){
        num = num * i % mod;
    }

    long long facn = 1;
    for(int i = 1; i <= n; i++){
        facn = facn * i % mod;
    }
    int den = power(facn, mod - 2);

    int res = num * den % mod;

    cout<<res;

    return 0;
}
