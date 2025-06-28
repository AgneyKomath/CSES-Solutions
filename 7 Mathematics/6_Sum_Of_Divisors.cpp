#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

int sum(int n){
    int v1 = n;
    int v2 = n+1;

    if(v1%2==0) v1/=2;
    else v2/=2;

    v1 %= mod;
    v2 %= mod;

    int res = v1*v2 % mod;
    
    return res;
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

    int res = 0;

    for(int i = 1;i*i<=n;i++){
        int v = n/i;
        
        int t1 = ((v-i)*i) %mod;

        int t2 = sum(v);

        int t3 = sum(i-1);

        int t = (t1 + t2 - t3 + mod) % mod;

        res = (res + t) % mod;
    }

    cout<<res;
    
    return 0;
}
