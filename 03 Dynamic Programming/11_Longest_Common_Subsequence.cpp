#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> a(n), b(m);
    for(int &i : a) cin>>i;
    for(int &i : b) cin>>i;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i + 1][j + 1] = max({dp[i][j + 1], dp[i + 1][j], (a[i] == b[j]) + dp[i][j]});
        }
    }

    cout<<dp[n][m]<<'\n';

    vector<int> lcs;

    int r = n, c = m;
    while(dp[r][c] != 0){
        if(dp[r][c] == dp[r - 1][c]) r--;
        else if(dp[r][c] == dp[r][c - 1]) c--;
        else{
            r--, c--;
            lcs.push_back(a[r]);
        }
    }

    for(int i = dp[n][m] - 1; i >= 0; i--) cout<<lcs[i]<<' ';

    return 0;
}
