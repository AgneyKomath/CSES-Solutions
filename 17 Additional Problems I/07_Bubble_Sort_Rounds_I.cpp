#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, a[i].second - i);
    }
    cout<<res;

    return 0;
}