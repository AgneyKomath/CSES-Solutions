#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    if(n>m) swap(n, m);

    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(i==j) dp[i][j] = 0;
            else{
                for(int k = 1; k<j; k++) dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                for(int k = 1; k<i; k++) dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }
        }
    }

    cout<<dp[n][m];

    return 0;
}
