#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int y, x;
        cin>>y>>x;

        int grp = max(x, y);
        long long mid = 1ll * grp * (grp - 1) + 1;

        int diff = x - y;

        long long res = grp & 1 ? mid + diff : mid - diff;

        cout<<res<<'\n';
    }

    return 0;
}
