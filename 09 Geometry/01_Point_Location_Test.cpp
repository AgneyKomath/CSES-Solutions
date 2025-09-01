#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        long long x = 1ll * (y3 - y1) * (x2 - x1) + 1ll * x1 * (y2 - y1);

        long long xreal = 1ll * x3 * (y2 - y1);

        if(xreal < x) cout<<"LEFT\n";
        else if(xreal > x) cout<<"RIGHT\n";
        else cout<<"TOUCH\n";
    }
    
    return 0;
}
