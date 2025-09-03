#include <bits/stdc++.h>
using namespace std;

int power(int a, int b, int mod){
    int res = 1;
    for(; b; a = 1ll * a * a % mod, b /= 2){
        if(b & 1) res = 1ll * res * a % mod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    const int mod = 1e9 + 7;

    for(int i = 0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;

        int p = power(b, c, mod - 1);
        int res = power(a, p, mod);

        cout<<res<<'\n';
    }
    
    return 0;
}
