#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    // prev : probability that largest number isn't greater than i
    long double prev = 1, res = 0;
    for(int i = k; i >= 1; i--){
        long double curr = pow(((long double) i - 1) / i, n);
        res += i * prev * (1 - curr);
        prev *= curr;
    }

    cout<<fixed<<setprecision(6)<<res;

    return 0;
}
