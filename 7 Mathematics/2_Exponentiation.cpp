#include <bits/stdc++.h>
#define int long long
using namespace std;

static constexpr int mod = 1e9+7;

// int power(int a, int b) {
//     if (b == 0) return 1;
//     int res = power(a, b / 2) % mod;
//     int ans = (res * res) % mod;
//     if (b % 2) return (ans * a) % mod;
//     else return ans;
// }

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;

        // cout<<power(a,b)<<'\n';

        int res=1;
        for(;b>0;b >>= 1){
            if(b&1) res = res*a %mod;
            a = a*a %mod;
        }
        cout<<res<<'\n';

        // int res=1;
        // for(int i=30;i>=0;i--){
        //     res = (res*res)%mod;
        //     if( b&(1<<i)) res = res*a %mod;
        // }
        // cout<<res<<'\n';
    }
    
    
    return 0;
}
