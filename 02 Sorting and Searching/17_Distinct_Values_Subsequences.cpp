#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    sort(a.begin(), a.end());

    vector<int> freq;
    for(int i = 0; i<n; i++){
        if(freq.empty() || a[i] != a[i-1]) freq.push_back(1);
        else freq.back()++;
    }

    int res = 1;
    for(int v : freq){
        // Each value you have v+1 choices. Take any one of them or dont take at all. 
        res = (1ll * res * (1 + v)) % mod;
    }

    // Remove empty Subsequence
    res = (res-1+mod) % mod;

    cout<<res<<'\n';
    
    return 0;
}
