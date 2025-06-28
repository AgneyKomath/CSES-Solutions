#include <bits/stdc++.h>
using namespace std;

int MIN[200001][18];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++) cin>>MIN[i][0];
    int mxLog = log2(n) + 1;
    for (int j = 1; j < mxLog; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            MIN[i][j] = min(MIN[i][j - 1], MIN[i + (1 << (j - 1))][j - 1]);
        }
    }
    

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int j = log2(r-l+1);
        cout<<min(MIN[l][j],MIN[r-(1<<j)+1][j])<<'\n';
    }
    
    return 0;
}
