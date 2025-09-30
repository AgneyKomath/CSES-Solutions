#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());
    map<int, vector<int>> mp;
    for(int i = 0; i<n; i++) mp[b[i]].push_back(i);
    int res = 0;

    for(int i = n-1; i>=0; i--){
        res = max(res, i - mp[a[i]].back());
        mp[a[i]].pop_back();
    }
    
    cout<<res;
    
    return 0;
}
