#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    map<long long, int> mp;
    mp[0] = 1;

    long long curr = 0, res = 0;
    for(int i : a){
        curr += i;
        res += mp[curr - x];
        mp[curr]++;
    }

    cout<<res;

    return 0;
}
