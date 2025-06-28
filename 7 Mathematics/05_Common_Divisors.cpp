#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 1e6;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> st(mxn+1,0);

    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int v;cin>>v;
        st[v]++;
    }

    for(int i = mxn;i>=1;i--){
        int cnt = 0;
        for(int j = i;j<=mxn;j+=i) cnt += st[j];
        if(cnt>=2){
            cout<<i;
            break;
        }
    }

    
    return 0;
}
