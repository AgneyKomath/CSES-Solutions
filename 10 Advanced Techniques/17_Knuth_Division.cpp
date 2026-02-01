#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<ll> pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    vector<vector<int>> opt(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    for(int r = 0; r < n; r++){
        for(int l = r - 1; l >= 0; l--){
            int optl = opt[l][r - 1], optr = opt[l + 1][r];
            pair<ll, int> best = {INF, optl};
            for(int k = optl; k <= min(optr, r - 1); k++){
                best = min(best, make_pair(dp[l][k] + dp[k + 1][r], k));
            }
            dp[l][r] = best.first + pref[r + 1] - pref[l];
            opt[l][r] = best.second;
        }
    }

    cout<<dp[0][n - 1];

    return 0;
}
