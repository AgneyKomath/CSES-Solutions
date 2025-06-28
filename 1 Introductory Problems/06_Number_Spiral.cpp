#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long long y,x;
        cin>>y>>x;

        long long grp = max(y, x);
        long long mid = grp * (grp - 1) + 1;

        long long diff = x - y;

        long long res;

        if(grp & 1) res = mid + diff;
        else res = mid - diff; 

        cout<<res<<'\n';
    }

    
    return 0;
}
