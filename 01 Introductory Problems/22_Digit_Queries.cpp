#include <bits/stdc++.h>
using namespace std;

int solve(long long x){
    int digit = 1;
    long long pow10 = 1;
    while(x){
        long long totalDigits = digit * 9 * pow10;
        if(totalDigits>x) break;
        x -= totalDigits;
        digit++;
        pow10 *= 10;
    }

    long long remNums = x/digit;
    x %= digit;

    long long lastNum = pow10 + remNums; 
    
    return to_string(lastNum)[x]-'0';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;
    while(q--){
        long long k;
        cin>>k;
        int res = solve(k-1);
        cout<<res<<'\n';
    }
    
    return 0;
}
