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

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int i:c){
        for(int j = i; j<=x; j++){
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
    
    cout<<dp[x];

    return 0;
}
