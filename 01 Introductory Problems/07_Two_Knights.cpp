#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int k = 1; k<=n; k++){
        long long res = (1ll * (k * k) * (k * k - 1)) / 2 - 4ll * (k - 1) * (k - 2);
        cout<<res<<'\n';
    }

    return 0;
}
