#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<string> a(n);
    for(auto &i:a) cin>>i;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j] == '*') continue;
            if(i != 0 && j != 0) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            else if(i != 0) dp[i][j] = dp[i-1][j];
            else if(j != 0) dp[i][j] = dp[i][j-1];
            else dp[i][j] = 1;
        }
    }
    cout<<dp[n-1][n-1];

    return 0;
}
