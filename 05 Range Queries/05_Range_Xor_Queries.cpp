#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i = 0; i<n; i++){
        pref[i+1] = pref[i] ^ a[i];
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        int res = pref[r] ^ pref[l-1];
        cout<<res<<'\n';
    }
    
    return 0;
}
