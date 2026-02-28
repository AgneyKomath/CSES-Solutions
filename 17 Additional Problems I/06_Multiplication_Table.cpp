#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;

    long long lo = 1, hi = n * n;
    while(lo < hi){
        long long mid = (lo + hi) / 2, less = 0;
        for(int i = 1; i <= n; i++){
            less += min(n, mid / i);
        }
        if(less > n * n / 2) hi = mid;
        else lo = mid + 1;
    }

    cout<<lo;

    return 0;
}