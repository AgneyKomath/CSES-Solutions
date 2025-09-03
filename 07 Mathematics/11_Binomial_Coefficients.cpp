#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mxn = 1e6;

int power(int a, int b){
    int res = 1;
    for(; b; a = 1ll * a * a % mod, b = b/2){
        if(b & 1) res = (1ll * res * a) % mod;
    }
    return res;
}

vector<int> fact(mxn+1), invfact(mxn+1);
void precompute(){
    fact[0] = 1;
    for(int i = 1; i<=mxn; i++){
        fact[i] = 1ll * fact[i-1] * i % mod;
    }
    invfact[mxn] = power(fact[mxn], mod-2);
    for(int i = mxn-1; i>=0; i--){
        invfact[i] = 1ll * invfact[i+1] * (i+1) % mod;
    }
}

int nCr(int a, int b){
    int div = 1ll * invfact[b] * invfact[a-b] % mod;
    return 1ll * fact[a] * div % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        cout<<nCr(a, b)<<'\n';
    }
    
    return 0;
}
