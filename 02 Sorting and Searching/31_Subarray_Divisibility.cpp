#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    long long res = 0;

    vector<int> mp(n, 0);
    mp[0] = 1;
    int sum = 0;
    for(int i:a){
        sum = ((sum + i) % n + n) % n;
        res += mp[sum];
        mp[sum]++;
    }

    cout<<res;
    
    return 0;
}
