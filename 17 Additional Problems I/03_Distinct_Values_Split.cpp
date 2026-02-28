#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());
    for(int &i : a) i = lower_bound(b.begin(), b.end(), i) - b.begin();

    vector<int> dp(n + 1, 0), cnt(n, 0);
    dp[0] = 1;
    long long curr = 0;
    for(int i = 0, j = 0; j < n; j++){
        curr = (curr + dp[j]) % mod;
        cnt[a[j]]++;
        while(cnt[a[j]] > 1){
            curr = (curr - dp[i] + mod) % mod;
            --cnt[a[i++]];
        }
        dp[j + 1] = curr;
    }

    cout<<dp[n];

    return 0;
}