#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int mod = 1e9 + 7;

    // answer is 2^n modulo mod
    int res = 1;
    for(int a = 2, b = n; b > 0; b /= 2, a = 1ll * a * a % mod){
        if(b & 1) res = 1ll * res * a % mod;
    }

    cout<<res;

    return 0;
}
