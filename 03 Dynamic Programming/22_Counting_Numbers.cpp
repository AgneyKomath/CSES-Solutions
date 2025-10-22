#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n;

long long dp[19][10][2][2][2];

long long f(int dig, int prev, bool t1, bool t2, bool lz){
    if(dig == n) return 1;
    auto &res = dp[dig][prev][t1][t2][lz];
    if(res != -1) return res;
    res = 0;

    int lb = t1 ? s1[dig] - '0' : 0, ub = t2 ? s2[dig] - '0' : 9;
    for(int i = lb; i <= ub; i++){
        if(!lz && i == prev) continue;
        bool nt1 = t1 && i == lb;
        bool nt2 = t2 && i == ub;
        bool nlz = lz && i == 0;
        res += f(dig + 1, i, nt1, nt2, nlz);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;

    s1 = to_string(a), s2 = to_string(b);
    n = s2.size();
    s1 = string(n - s1.size(), '0') + s1;

    memset(dp, -1, sizeof(dp));
    
    cout<<f(0, 0, 1, 1, 1);
    
    return 0;
}
