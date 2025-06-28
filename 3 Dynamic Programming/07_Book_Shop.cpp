#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin>>n>>x;

    vector<int> prices(n), pages(n);
    for(int &i:prices) cin>>i;
    for(int &i:pages) cin>>i;

    vector<int> dp(x+1, 0);

    for(int j = 0; j<n; j++){
        for(int i = x; i>=prices[j]; i--){
            dp[i] = max(dp[i], dp[i-prices[j]] + pages[j]);
        }
    }

    cout<<dp[x];
    
    return 0;
}
