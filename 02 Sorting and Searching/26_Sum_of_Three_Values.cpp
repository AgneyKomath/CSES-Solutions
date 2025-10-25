#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        int v;
        cin>>v;
        a[i] = {v, i + 1};
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        int target = x - a[i].first;

        for(int l = i + 1, r = n - 1; l < r; ){
            if(a[l].first + a[r].first > target) r--;
            else if(a[l].first + a[r].first < target) l++;
            else{
                cout<<a[i].second<<' '<<a[l].second<<' '<<a[r].second;
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";

    return 0;
}
