#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<long long> pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    auto query = [&](int l, int r){
        return pref[r + 1] - pref[l];
    };

    vector<vector<long long>> dp(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        dp[i][i] = a[i];
        for(int j = i - 1; j >= 0; j--){
            long long v1 = a[i] + query(j, i - 1) - dp[j][i - 1];
            long long v2 = a[j] + query(j + 1, i) - dp[j + 1][i];
            dp[j][i] = max(v1, v2);
        }
    }

    cout<<dp[0][n - 1];

    // // More Intuitive Pair DP
    // vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(n));
    // for(int i = 0; i < n; i++){
    //     dp[i][i] = {a[i], 0};
    //     for(int j = i - 1; j >= 0; j--){
    //         pair<long long, long long> p1 = {a[j] + dp[j + 1][i].second, dp[j + 1][i].first};
    //         pair<long long, long long> p2 = {a[i] + dp[j][i - 1].second, dp[j][i - 1].first};
    //         dp[j][i] = max(p1, p2);
    //     }
    // }
    // cout<<dp[0][n - 1].first;

    return 0;
}
