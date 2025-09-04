#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;
    
    int res = 0;
    map<int, int> mp;

    for(int i = 0, j = 0; j<n; j++){
        mp[a[j]]++;
        while(mp[a[j]] > 1){
            mp[a[i]]--;
            i++;
        }
        res = max(res, j - i + 1);
    }
    cout<<res;
    
    return 0;
}
