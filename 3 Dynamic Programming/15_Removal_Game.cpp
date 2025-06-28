#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<long long> pref(n+1, 0);
    for(int i = 0; i<n; i++) pref[i+1] = pref[i] + a[i];

    auto query = [&](int l, int r){
        return pref[r+1] - pref[l];
    };

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for(int i = 0; i<n; i++) dp[i][i] = a[i];

    for(int len = 1; len<n; len++){
        for(int i = 0; i+len<n; i++){
            int j = i + len;
            long long s1 = a[i] + query(i+1, j) - dp[i+1][j];
            long long s2 = a[j] + query(i, j-1) - dp[i][j-1];
            dp[i][j] = max(s1, s2);
        }
    }

    cout<<dp[0][n-1];

    return 0;
}
