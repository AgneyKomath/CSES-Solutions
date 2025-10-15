#include <bits/stdc++.h>
using namespace std;

using ll = long long;   

ll cross(pair<int, int> & a, pair<int, int> & b){
    return 1ll * a.first * b.second - 1ll * b.first * a.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<pair<int, int>> a(n);
    for(auto &[x, y] : a) cin>>x>>y;

    ll res = cross(a.back(), a[0]);
    for(int i = 1; i < n; i++) res += cross(a[i - 1], a[i]);

    cout<<abs(res);
    
    return 0;
}
