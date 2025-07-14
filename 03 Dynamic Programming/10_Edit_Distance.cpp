#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, t;
    cin>>s>>t;

    int n = s.length(), m = t.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else{
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                int cost = dp[i-1][j-1] + (s[i-1] != t[j-1]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }   
    }

    cout<<dp[n][m]<<'\n';
    
    return 0;
}
