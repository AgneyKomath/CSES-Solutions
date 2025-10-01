#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,x;
    cin>>n>>x;
    
    vector<int> a(n);
    for(int &i:a) cin>>i;
    
    // min number of rides then min number of current weight
    vector<pair<int, int>> dp(1<<n, {1e9, 1e9});
    dp[0] = {0, 0}; 
    for(int mask = 1; mask < (1 << n); mask++){
        for(int i = 0; i<n; i++){
            if(!((mask >> i) & 1)) continue;
            int newMask = mask & ~(1 << i);
            int rides = dp[newMask].first + (dp[newMask].second + a[i] > x);
            int weight = dp[newMask].second + a[i] > x ? a[i] : dp[newMask].second + a[i];
            dp[mask] = min(dp[mask], {rides, weight});
        }
    }

    cout<<1 + dp.back().first;
    
    return 0;
}
