#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int sum = n * (n + 1) / 2;
    if(sum & 1){
        cout<<0;
        return 0;
    }
    sum /= 2;
    
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    // Loop till n - 1 to avoid double counting sets since exactly half the sets will contain n
    for(int i = 1; i < n; i++){
        for(int j = sum; j >= i; j--){
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    cout<<dp[sum];

    return 0;
}
