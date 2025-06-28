#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,q;
    cin>>n>>q;
    vector<int> pref(n+1,0);
    for(int i =1;i<=n;i++){
        cin>>pref[i];
        pref[i] ^= pref[i-1];
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(pref[b]^pref[a-1])<<'\n';
    }
    
    
    return 0;
}
