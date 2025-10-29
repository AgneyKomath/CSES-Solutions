#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(k);
    for(int &i : a) cin>>i;
    sort(a.begin(), a.end());

    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j : a){
            if(j > i) break;
            if(dp[i - j] == 0){
                dp[i] = 1;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<(dp[i] ? "W" : "L");
    }

    return 0;
}
