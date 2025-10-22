#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, mxn = 1e6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    dp[i][0] : if the ith floor is split
    dp[i][1] : if the ith floor is joined
    */
    vector<array<int, 2>> dp(mxn + 1);
    dp[1] = {1, 1};

    for(int i = 2; i <= mxn; i++){
        dp[i][0] = (4ll * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (2ll * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0] + dp[n][1]) % mod<<'\n';
    }

    return 0;
}
