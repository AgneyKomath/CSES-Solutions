#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;
    
    int res = 0;
    map<int,int> mp;

    for(int i = 0, j = 0; j<n; j++){
        mp[a[j]]++;
        while(mp[a[j]] > 1){
            mp[a[i]]--;
            i++;
        }
        res = max(res, j - i + 1);
    }
    cout<<res;

    // // Coordinate Compression
    // int n;cin>>n;
    // vector<int> a(n);
    // for(int &i:a)cin>>i;

    // vector<int> b(a);
    // sort(b.begin(),b.end());
    // b.erase(unique(b.begin(),b.end()),b.end());
    // auto compress = [&](int val){
    //     return lower_bound(b.begin(),b.end(),val) - b.begin();
    // };
    // for(int &i:a) i = compress(i);

    // int res= 1;
    // vector<int> mp(b.size(),0);
    // for(int i=0,j=0;j<n;j++){
    //     mp[a[j]]++;
    //     while(mp[a[j]]>1){
    //         mp[a[i]]--;
    //         i++;
    //     }
    //     res = max(res,j-i+1);
    // }

    // cout<<res<<'\n';

    
    return 0;
}
