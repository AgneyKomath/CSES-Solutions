#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    // Number of Dearrangements
    const int mod = 1e9 + 7;

    int curr = 1;
    for(int i = 1; i <= n; i++){
        curr = (1ll * i * curr + (i & 1 ? -1 : 1)) % mod; 
    }

    cout<<curr;

    return 0;
}
