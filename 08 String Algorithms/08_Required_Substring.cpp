#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
ll power(ll a, ll b){
    ll res = 1;
    for(; b; b /= 2, a = a * a % mod){
        if(b & 1) res = res * a % mod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    string s;
    cin>>s;

    int m = s.size();

    vector<int> lps(m);
    for(int i = 1; i < m; i++){
        int j = lps[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = lps[j - 1];
        }
        if(s[i] == s[j]) j++;
        lps[i] = j;
    }

    auto trans = [&](int curr, char c){
        while(curr > 0 && s[curr] != c) curr = lps[curr - 1];
        if(s[curr] == c) curr++;
        return curr;
    };

    vector<vector<ll>> dp(n + 1, vector<ll>(m, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int c = 'A'; c <= 'Z'; c++){
                int nxt = trans(j, c);
                if(nxt != m){
                    dp[i + 1][nxt] = (dp[i + 1][nxt] + dp[i][j]) % mod;
                }
            }
        }
    }

    ll sum = accumulate(dp[n].begin(), dp[n].end(), 0ll) % mod;

    ll res = (power(26, n) - sum + mod) % mod;

    cout<<res;

    return 0;
}