#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    const int mod = 1e9 + 7;

    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;

        int res = 1;
        for(; b; a = 1ll * a * a % mod, b = b/2){
            if(b & 1){
                res = (1ll * res * a) % mod;
            }
        }
        cout<<res<<'\n';
    }
    
    return 0;
}
