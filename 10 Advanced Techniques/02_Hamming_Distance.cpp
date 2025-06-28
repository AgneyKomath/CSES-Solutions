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

    int n, k;
    cin>>n>>k;

    vector<int>a(n);
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        int sum = 0;
        for(int j = 0;j<k;j++){
            if(s[j]=='1') sum += (1<<(k-j-1));
        }
        a[i] = sum;
    }

    int res = k;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int v = __builtin_popcount(a[i]^a[j]);
            res = min(res, v);
        }
    }
    cout<<res<<'\n';
    
    return 0;
}
