#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin>>n>>a>>b;

    int len = n * 6;
    vector<double> dp(len + 1, 0), ndp;
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        ndp.assign(len + 1, 0);
        for(int j = i; j + 6 <= len; j++){
            for(int k = 1; k <= 6; k++){
                ndp[j + k] += dp[j] / 6;
            }
        }
        swap(dp, ndp);
    }

    double res = 0;
    for(int i = a; i <= b; i++) res += dp[i];

    cout<<fixed<<setprecision(6)<<res;

    return 0;
}
