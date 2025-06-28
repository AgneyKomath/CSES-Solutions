#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    // answer is 2^n modulo mod
    long long res = 1;
    for(int a = 2, b = n; b; b /= 2, a = 1ll * a * a % mod){
        if(b & 1) res = 1ll * res * a % mod;
    }

    cout<<res;
    
    return 0;
}
