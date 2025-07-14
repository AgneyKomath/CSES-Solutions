#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> c(n);
    for(int &i:c) cin>>i;

    vector<int> dp(x+1, 1e7);
    dp[0] = 0;
    for(int i:c){
        for(int j = i; j<=x; j++) dp[j] = min(dp[j], 1 + dp[j-i]);
    }
    
    int res = -1;
    if(dp[x] != 1e7) res = dp[x];
    
    cout<<res;
    
    return 0;
}
