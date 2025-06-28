#include <bits/stdc++.h>
#define int long long
using namespace std;


// int power(int a, int b,int mod) {
//     if (b == 0) return 1;
//     int res = power(a, b / 2,mod) % mod;
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

    
    const int mod = 1e9+7;
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        // int p1 = power(b,c,mod-1);
        // cout<<power(a,p1,mod)<<'\n';

        int res1=1,res = 1;
        for(;c>0;c >>= 1){
            if(c&1) res1 = res1*b %(mod-1);
            b = b*b %(mod-1);
        }

        for(;res1>0;res1 >>= 1){
            if(res1&1) res = res*a %mod;
            a = a*a %mod;
        }
        cout<<res<<'\n';
    }
    
    return 0;
}
//928742408