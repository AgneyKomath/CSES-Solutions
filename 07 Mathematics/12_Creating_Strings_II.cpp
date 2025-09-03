#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int power(int a, int b){
    int res = 1;
    for(; b; a = 1ll * a * a % mod, b = b/2){
        if(b & 1) res = (1ll * res * a) % mod;
    }
    return res;
}

int inv(int n){
    return power(n, mod-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // answer is n! / (cnt(a)! * cnt(b)! * ... * cnt(z)!)

    string s;
    cin>>s;

    int n = s.size();

    vector<int> fact(n+1);
    fact[0] = 1;
    for(int i = 1; i<=n; i++){
        fact[i] = 1ll * fact[i-1] * i % mod;
    }

    int freq[26]{};
    for(char c:s) freq[c-'a']++;

    int res = fact[n];
    for(int i:freq){
        res = 1ll * res * inv(fact[i]) % mod;
    }

    cout<<res;

    return 0;
}
