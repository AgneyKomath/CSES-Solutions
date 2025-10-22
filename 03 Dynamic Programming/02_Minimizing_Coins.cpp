#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> coins(n);
    for(int &i : coins) cin>>i;

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for(int i : coins){
        for(int j = i; j <= x; j++){
            dp[j] = min(dp[j], 1 + dp[j - i]);
        }
    }

    cout<<(dp[x] == INF ? -1 : dp[x]);

    return 0;
}
