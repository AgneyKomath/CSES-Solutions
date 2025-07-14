#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // O(nlogn) solution, my own
    int n;
    cin>>n;
    vector<array<int,3>> a(n);
    for(auto &[e, s, m]:a) cin>>s>>e>>m;
    sort(a.begin(), a.end());

    auto binarySearch=[&](int val){
        int lo = 0, hi = n-1;
        int res = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(a[mid][0]<val){
                res = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return res;
    };

    vector<int> dp(n+1,0);
    for(int i = 0;i<n;i++){
        dp[i+1] = dp[i];
        int id = binarySearch(a[i][1]);
        dp[i+1] = max(dp[i+1], dp[id+1] + a[i][2]);
    }

    cout<<dp[n];
    
    // //O(nlogn) solution better implementation
    // int n;
    // cin>>n;
    // vector<tuple<int,int,int>> a(n);
    // for(auto &[e,s,p]:a){
    //     cin>>s>>e>>p;
    // }
    // sort(a.begin(),a.end());
    
    // vector<int> dp(n+1,0);
    // vector<int> endtimes(n,0);
    // for(int i=0;i<n;i++) endtimes[i] = get<0>(a[i]);
    // for(int i=0;i<n;i++){
    //     auto [_,s,p] = a[i];
    //     int ind = lower_bound(endtimes.begin(),endtimes.begin()+i,s) - endtimes.begin();
    //     dp[i+1] = max(dp[i],dp[ind]+p);
    // }
    // cout<<dp[n]<<'\n';


    return 0;
}
