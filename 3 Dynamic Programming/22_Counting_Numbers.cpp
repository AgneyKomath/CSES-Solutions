#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[20][11][2][2];
// dp[digit position][previous digit][tight][leading zeroes]
// 11 because -1 is also there as sentinel value

vector<int> digits;

int rec(int pos, int prev, bool tight, bool lz){
    if(pos==digits.size()) return 1;
    if(dp[pos][prev+1][tight][lz] != -1) return dp[pos][prev+1][tight][lz];

    int res = 0;
    
    int limit = (tight? digits[pos] : 9);
    for(int d = 0; d<=limit; d++){
        if(!lz & prev==d) continue;
        res += rec(pos+1, d, tight && (d==limit), lz && (d==0));
    }

    return dp[pos][prev+1][tight][lz] = res; 
}

int helper(int x){
    if(x<0) return 0;

    memset(dp, -1, sizeof(dp));

    digits.clear();
    while(x){
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());

    return rec(0, -1, 1, 1);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a,b;
    cin>>a>>b;
    
    int val1 = helper(b);
    int val2 = helper(a-1);
    
    // cout<<val1<<' '<<val2<<'\n';
    
    cout<<val1-val2;

    return 0;
}
