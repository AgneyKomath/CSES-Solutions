#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b;
    cin>>n>>a>>b;

    if(a==0 && b==0){
        cout<<"YES\n";
        for(int i = 1; i<=n; i++) cout<<i<<" \n"[i==n-1];
        for(int i = 1; i<=n; i++) cout<<i<<" \n"[i==n-1];
        return;
    }
    if(a==0 || b==0 || a+b>n){
        cout<<"NO\n";
        return;
    }

    vector<int> ra, rb;
    for(int i = 1; i<=b; i++){
        ra.push_back(i);
        rb.push_back(i+a);
    }
    for(int i = 1; i<=a; i++){
        ra.push_back(i+b);
        rb.push_back(i);
    }
    for(int i = a+b+1; i<=n; i++){
        ra.push_back(i);
        rb.push_back(i);
    }

    cout<<"YES\n";
    for(int i = 0; i<n; i++) cout<<ra[i]<<" \n"[i==n-1];
    for(int i = 0; i<n; i++) cout<<rb[i]<<" \n"[i==n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
