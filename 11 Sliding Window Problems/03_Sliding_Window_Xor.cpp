#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int x, a, b, c;
    cin>>x>>a>>b>>c;

    int prev = x, res = x;
    for(int i = 1; i < n; i++){
        prev = (1ll * a * prev + b) % c;
        int cnt = min(k, min(i + 1, n - i));
        if(cnt & 1) res ^= prev;
    }

    cout<<res;

    return 0;
}
