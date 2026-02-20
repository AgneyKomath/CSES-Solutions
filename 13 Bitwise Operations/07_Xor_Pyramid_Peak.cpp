#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int res = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        // Check Parity of C(n - 1, i)
        if((~(n - 1) & i) == 0) res ^= x;
    }
    cout<<res;

    return 0;
}