#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while(t--){
        long long n;
        cin>>n;
        n--;

        int digit = 1;
        long long pow10 = 1;
        while(n){
            long long totalDigits = digit * 9 * pow10;
            if(totalDigits > n) break;
            n -= totalDigits;
            digit++;
            pow10 *= 10;
        }

        long long remNums = n / digit;
        n %= digit;

        long long lastNum = pow10 + remNums; 
        
        int res = to_string(lastNum)[n] - '0';
        cout<<res<<'\n';
    }

    return 0;
}
