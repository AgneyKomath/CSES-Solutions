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

    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int &i:a) cin>>i; 

    map<int,int> mp;
    mp[0]++;
    int curr =0,res=0;

    for(int i=0;i<n;i++){
        curr += a[i];
        res += mp[curr-x];
        mp[curr]++;
    }
    cout<<res<<'\n';

    return 0;
}
