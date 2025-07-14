#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;
long long power(long long a, long long b){
    long long res = 1;
    for(; b; b/=2, a = a * a % mod){
        if(b&1) res = res * a % mod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin>>s;

    int n = s.size();

    vector<int> facs(n+1), invfacs(n+1);
    facs[0] = 1;
    for(int i = 1; i<=n; i++) facs[i] = 1ll * facs[i-1] * i % mod;
    invfacs[n] = power(facs[n], mod-2);
    for(int i = n-1; i>=0; i--) invfacs[i] = 1ll * invfacs[i+1] * (i+1) % mod;

    int freq[26]{};
    for(char c:s) freq[c-'a']++;
    long long res = facs[n];
    for(int i:freq){ 
        res = res * invfacs[i] % mod;
    }

    cout<<res;
    
    return 0;
}
