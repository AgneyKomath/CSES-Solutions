#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    long long res = 0, sum = 0;
    map<long long, int> mp;
    mp[0] = 1;
    for(int i:a){
        sum += i;
        res += mp[sum-x];
        mp[sum]++;
    }

    cout<<res;
    
    return 0;
}
