#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    
    vector<int> x(n);
    for(int &i:x) cin>>i;

    vector<vector<long long>> dp(n, vector<long long>(m+2, 0));
    if(x[0]==0){
        for(int i = 1; i<=m; i++) dp[0][i] = 1;
    }
    else dp[0][x[0]] = 1;

    for(int i = 1; i<n; i++){
        if(x[i]==0){
            for(int j = 1; j<=m; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod;
            }
        }
        else{
            dp[i][x[i]] = (dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1]) % mod;
        }
    }

    int res = 0;
    for(int i = 1; i<=m; i++) res = (res + dp[n-1][i]) % mod;
    cout<<res;

    return 0;
}
