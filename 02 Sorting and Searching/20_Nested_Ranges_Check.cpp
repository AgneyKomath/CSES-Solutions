#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i++){
        int s, e;
        cin>>s>>e;
        a[i] = {s, e, i};
    }

    sort(a.begin(), a.end(), [](auto &x, auto &y){
        if(x[1] == y[1]) return x[0] > y[0];
        return x[1] < y[1];
    });

    vector<int> contains(n, 0);
    for(int i = 0, mx = 0; i < n; i++){
        auto [s, e, id] = a[i];
        if(s <= mx) contains[id] = 1;
        mx = max(mx, s);
    }

    vector<int> contained(n, 0);
    for(int i = n - 1, mn = 2e9; i >= 0; i--){
        auto [s, e, id] = a[i];
        if(s >= mn) contained[id] = 1;
        mn = min(mn, s);
    }

    for(int i : contains) cout<<i<<' ';
    cout<<'\n';
    for(int i : contained) cout<<i<<' ';

    return 0;
}
