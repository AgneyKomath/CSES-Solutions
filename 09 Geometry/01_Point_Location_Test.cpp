#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        int x = ((y3-y1)*(x2-x1)) + x1*(y2-y1);

        x3 *= y2-y1;

        if(x==x3) cout<<"TOUCH\n";
        else if(x3<x) cout<<"LEFT\n";
        else cout<<"RIGHT\n";

    }
    
    
    return 0;
}
