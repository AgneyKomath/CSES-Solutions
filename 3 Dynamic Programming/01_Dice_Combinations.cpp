#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        dp[i] = 0;
        for(int j = 1; j<=6; j++){
            if(i-j>=0) dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    cout<<dp[n];
    
    return 0;
}
