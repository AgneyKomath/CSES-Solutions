#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for(int l = 0, r = n - 1; l < r; ){
        if(a[l].first + a[r].first > x) r--;
        else if(a[l].first + a[r].first < x) l++;
        else{
            cout<<a[l].second<<' '<<a[r].second;
            return 0;
        }
    }

    cout<<"IMPOSSIBLE";

    // // Map Approach
    // int n, x;
    // cin>>n>>x;

    // map<int, int> mp;
    // for(int i = 1; i <= n; i++){
    //     int v;
    //     cin>>v;
    //     if(mp.count(x - v)){
    //         cout<<i<<' '<<mp[x - v];
    //         return 0;
    //     }
    //     mp[v] = i;
    // }

    // cout<<"IMPOSSIBLE";

    return 0;
}
