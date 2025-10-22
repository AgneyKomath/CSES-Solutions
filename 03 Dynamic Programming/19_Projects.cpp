#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<array<int, 3>> a(n);
    for(auto &[e, s, c] : a) cin>>s>>e>>c;

    sort(a.begin(), a.end());
    vector<int> endtimes(n + 1);
    endtimes[0] = 0;
    for(int i = 0; i < n; i++) endtimes[i + 1] = a[i][0];

    vector<long long> dp(n + 1);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        auto [e, s, c] = a[i];
        int id = lower_bound(endtimes.begin(), endtimes.end(), s) - endtimes.begin() - 1;
        dp[i + 1] = max(dp[i], dp[id] + c); 
    }

    cout<<dp[n];

    return 0;
}
