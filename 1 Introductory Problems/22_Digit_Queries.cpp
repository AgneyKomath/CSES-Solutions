#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int x){
    int pow = 10, curr = 1;
    while(x>pow){
        x -= pow;
        pow*= 10;
        curr++;
    }
    pow /= 10;
    
    int div = x / curr;
    int rem = x%curr;
    pow += div;
    return pow;



}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;
    while(q--){
        int val;
        cin>>val;
        int res = solve(val-1);
        cout<<res<<'\n';
    }
    
    
    return 0;
}
