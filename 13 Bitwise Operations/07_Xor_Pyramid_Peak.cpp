#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int m = n - 1;
    
    // answer is mC0 * a[0] ^ mC1 * a[1] ^ ... ^ mCm * a[n-1]
    // because of xor this reduces to parity of binomial coefficients of m
    // if mCi is odd, xor a[i] to result
    // check if mCi is 1 modulo 2
    // only odd if every 1-bit in i sits unders a 1-bit in m (Lucas' Theorem)
    // i must be a submask of m basically
    // i & ~m checks that

    int res = 0;
    for(int i = 0; i <= m; i++){
        int v;
        cin>>v;
        if((i & ~m) == 0) res ^= v; 
    }

    cout<<res;
    
    return 0;
}
