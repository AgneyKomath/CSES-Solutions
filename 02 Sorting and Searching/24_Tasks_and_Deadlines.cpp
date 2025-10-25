#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> a(n);
    for(auto &[t, d] : a) cin>>t>>d;

    sort(a.begin(), a.end());

    long long curr = 0, res = 0;
    for(auto [t, d] : a){
        curr += t;
        res += d - curr;
    }

    cout<<res;

    return 0;
}
