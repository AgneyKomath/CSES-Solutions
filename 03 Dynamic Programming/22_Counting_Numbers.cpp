#include <bits/stdc++.h>
using namespace std;

long long dp[20][11][2][2];
// dp[digit position][previous digit][tight][leading zeroes]
// 11 because -1 is also there as sentinel value

vector<int> digits;

long long rec(int pos, int prev, bool tight, bool lz){
    if(pos==(int)digits.size()) return 1;
    if(dp[pos][prev+1][tight][lz] != -1) return dp[pos][prev+1][tight][lz];

    long long res = 0;
    
    int limit = (tight? digits[pos] : 9);
    for(int d = 0; d<=limit; d++){
        if(!lz && prev==d) continue;
        res += rec(pos+1, d, tight && (d==limit), lz && (d==0));
    }

    return dp[pos][prev+1][tight][lz] = res; 
}

long long helper(long long x){
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a,b;
    cin>>a>>b;
    
    long long val1 = helper(b);
    long long val2 = helper(a-1);
        
    cout<<val1-val2;

    return 0;
}
