#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    //Binary Search Solution O(nlogn)
    vector<int> lis;
    for(int i:a){
        auto it = lower_bound(lis.begin(), lis.end(),i);
        if(it==lis.end()) lis.push_back(i);
        else *it = i;
    }
    cout<<lis.size();
    
    // //DP Solution O(n^2)
    // int res=1;
    // int dp[n];
    // for(int i=0;i<n;i++){
    //     dp[i] = 1;
    //     for(int j=i-1;j>=0;j--){
    //         if(a[j]>=a[i]) continue;
    //         dp[i] = max(dp[i],dp[j]+1);
    //     }
    //     res = max(res,dp[i]);
    // }
    // cout<<res;

    return 0;
}
