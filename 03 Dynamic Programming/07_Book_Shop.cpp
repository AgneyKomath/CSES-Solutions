#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> cost(n), value(n);
    for(int &i : cost) cin>>i;
    for(int &i : value) cin>>i;

    vector<int> dp(x + 1, 0);
    
    for(int i = 0; i < n; i++){
        for(int j = x; j >= cost[i]; j--){
            dp[j] = max(dp[j], value[i] + dp[j - cost[i]]);
        }
    }

    cout<<dp[x];

    return 0;
}
