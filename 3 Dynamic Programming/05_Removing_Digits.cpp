#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> dp(n+1, 1e6);
    dp[0] = 0;
    
    for(int i = 1; i<=n; i++){
        int num = i;
        while(num){
            int rem = num%10;
            dp[i] = min(dp[i], 1 + dp[i-rem]);
            num /= 10;
        }
    }
    cout<<dp[n];

    
    return 0;
}
