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

    int n;
    cin>>n;

    int sm = 0, mx=0;
    for(int i=0;i<n;i++){
        int v; cin>>v;
        mx = max(mx, v);
        sm += v;
    }

    if(sm-mx>mx) cout<<sm;
    else cout<<2*mx;

    // int n;
    // cin>>n;
    // vector<int> a(n);
    // for(int &i:a) cin>>i;
    // sort(a.begin(),a.end());

    // int sum = accumulate(a.begin(),a.begin()+n-1,0ll);
    // int last = a.back();
    
    // int res;

    // if(last<sum) res = sum + last;
    // else res = 2*last;
    
    // cout<<res<<'\n';

    return 0;
}
