#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int x, a, b, c;
    cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0] = x;
    for(int i = 1; i<n; i++){
        arr[i] = (1ll * a * arr[i-1] + b) % c;
    }

    vector<int> pref(n), suff(n);
    for(int i = 0; i<n; i++){
        if(i%k==0) pref[i] = arr[i];
        else pref[i] = arr[i] | pref[i-1];
    }

    for(int i = n/k * k - 1; i>=0; i--){
        if(i%k==k-1) suff[i] = arr[i];
        else suff[i] = arr[i] | suff[i+1];
    }

    int res = 0;
    for(int i = 0; i+k-1<n; i++){
        int l = i, r = i+k-1;
        int v = pref[r] | suff[l];
        res ^= v;
    }
    cout<<res;
    
    return 0;
}
