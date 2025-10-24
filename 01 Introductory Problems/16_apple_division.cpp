#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int & i : a) cin>>i;

    long long res = 1e9;
    for(int i = 0; i < (1 << n); i++){
        long long curr = 0;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1) curr += a[j];
            else curr -= a[j];
        }
        res = min(res, abs(curr));
    }

    cout<<res;

    return 0;
}
