#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int div2(int n){
    long long div = 1;
    for(long long a = 2, b = mod-2; b; b /= 2, a = a * a % mod){
        if(b & 1) div = div * a % mod;
    }
    return n * div % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    int sum = n * (n+1) / 2;

    if(sum&1){
        cout<<0;
        return 0;
    }

    sum /= 2;
    
    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = sum; j>=i; j--){
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    } 

    int res = div2(dp[sum]);
    cout<<res;

    return 0;
}

//HINT: KNAPSACK LIKE
