#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<int> c(n);
    for(int &i:c) cin>>i;

    int sum = 0;
    for(int i:c) sum += i;

    vector<bool> dp(sum+1, 0);
    dp[0] = 1;
    for(int i:c){
        for(int j = sum; j>=i; j--){
            if(!dp[j]) dp[j] = dp[j-i];
        }
    }
    
    int res = 0;
    for(int i = 1; i<=sum; i++) res += dp[i];
    
    cout<<res<<'\n';
    for(int i = 1; i<=sum; i++){
        if(dp[i]) cout<<i<<' ';
    } 

    return 0;
}
