#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, a, b;
        cin>>n>>a>>b;

        if(a == 0 && b == 0){
            cout<<"YES\n";
            for(int i = 1; i <= n; i++) cout<<i<<" \n"[i == n];
            for(int i = 1; i <= n; i++) cout<<i<<" \n"[i == n];
            continue;
        }

        if(a == 0 || b == 0 || a + b > n){
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        for(int i = 1; i <= n; i++) cout<<i<<' ';
        cout<<'\n';

        int draws = n - a - b;
        for(int i = 0; i < draws; i++) cout<<i + 1<<' ';
        for(int i = draws; i < draws + b; i++) cout<<i + 1 + a<<' ';
        for(int i = draws + b; i < n; i++) cout<<i + 1 - b<<' ';
        cout<<'\n';
    }

    return 0;
}
