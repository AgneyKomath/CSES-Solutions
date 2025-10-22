#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<string> a(n);    
    for(auto &i : a) cin>>i;

    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++){
        int prev = 0;
        for(int j = 0; j < n; j++){
            if(a[i][j] == '*') dp[j + 1] = 0;
            else if(i == 0 && j == 0) dp[j + 1] = 1;
            else dp[j + 1] = (dp[j + 1] + prev) % mod;
            prev = dp[j + 1];
        }
    }

    cout<<dp[n];

    return 0;
}
