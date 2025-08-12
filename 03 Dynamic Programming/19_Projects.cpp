#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // O(nlogn) solution, my own
    int n;
    cin>>n;

    vector<array<int, 3>> a(n);
    for(auto &[e, s, val]:a){
        cin>>s>>e>>val;
    }

    sort(a.begin(), a.end());

    auto binSrch = [&](int val){
        int lo = 0, hi = n-1, res = -1;
        while(lo<=hi){
            int mid = (lo+hi) / 2;
            if(a[mid][0]>=val) hi = mid-1;
            else{
                res = mid;
                lo = mid+1;
            }
        }
        return res;
    };

    vector<long long> dp(n+1, 0);
    for(int i = 0; i<n; i++){
        int ind = binSrch(a[i][1]) + 1;
        dp[i+1] = max(dp[i], a[i][2] + dp[ind]);
    }
    cout<<dp[n];
    
    // //O(nlogn) solution better implementation
    // int n;
    // cin>>n;
    // vector<array<int, 3>> a(n);
    // for(auto &[e, s, val]:a){
    //     cin>>s>>e>>val;
    // }
    // sort(a.begin(), a.end());
    // vector<int> endtimes(n);
    // for(int i = 0; i<n; i++) endtimes[i] = a[i][0];
    // vector<long long> dp(n+1, 0);
    // for(int i = 0; i<n; i++){
    //     auto [e, s, val] = a[i];
    //     int ind = lower_bound(endtimes.begin(), endtimes.begin() + i, s) - endtimes.begin();
    //     dp[i+1] = max(dp[i], dp[ind] + val);
    // }
    // cout<<dp[n];

    return 0;
}
