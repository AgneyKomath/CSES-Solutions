#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

int power(int a, int b) {
    if (b == 0) return 1;
    int res = power(a, b / 2) % mod;
    int ans = (res * res) % mod;
    if (b % 2) return (ans * a) % mod;
    else return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    
    int nf = 1;

    int sf=0;
    int cnt = 0;

    int pf = 1;

    while(n--){
        int x, k;
        cin>>x>>k;
        sf = (sf + (x*k)%mod) % mod;
        cnt += k;
        
        pf = (pf*pf) % mod;
        int v = power(x,k+1);
        pf = (pf*v) % mod;
        pf = pf * nf % mod;
        
        nf = nf * (k+1) % mod;
    }

    sf = sf*power(2,cnt-1) % mod;

    cout<<nf<<' '<<sf<<' '<<pf;

    return 0;
}
