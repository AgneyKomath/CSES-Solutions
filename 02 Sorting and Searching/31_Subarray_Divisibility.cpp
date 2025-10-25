#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> mp(n, 0);
    mp[0] = 1;

    long long res = 0;
    int curr = 0;
    for(int i : a){
        curr = ((curr + i) % n + n) % n;
        res += mp[curr];
        mp[curr]++; 
    }

    cout<<res;

    return 0;
}
