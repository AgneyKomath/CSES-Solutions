#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin>>n>>x;

    vector<int> c(n);
    for(int &i:c) cin>>i;

    int dp[x+1];
    dp[0] = 1;
    for(int j = 1; j<=x; j++){
        dp[j] = 0;
        for(int i:c){
            if(j >= i) dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
    cout<<dp[x];

    return 0;
}
