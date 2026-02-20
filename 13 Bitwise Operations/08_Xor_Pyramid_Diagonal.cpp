#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    for(int i = 0; i < n; i++){
        int res = 0;
        for(int j = i; ; j = (j - 1) & i){
            res ^= a[j];
            if(j == 0) break;
        }
        cout<<res<<' ';
    }

    // // Interval Approach
    // vector<int> pref(n + 1);
    // pref[0] = 0;
    // for(int i = 0; i < n; i++) pref[i + 1] = pref[i] ^ a[i];
    // vector<int> res(n, 0);
    // vector<pair<int, int>> curr{{0, 0}};
    // for(int i = 0; i < n; i++){
    //     for(auto [l, r] : curr){
    //         res[i] ^= pref[r + 1] ^ pref[l];
    //     }
    //     vector<pair<int, int>> ncurr;
    //     for(auto [l, r] : curr){
    //         if(ncurr.empty() || ncurr.back().second < l - 1) ncurr.emplace_back(l, l);
    //         else ncurr.back().second = l;
    //         if(ncurr.empty() || ncurr.back().second < r) ncurr.emplace_back(r + 1, r + 1);
    //         else ncurr.back().second = r + 1;
    //     }
    //     swap(curr, ncurr);
    // }
    // for(int i : res) cout<<i<<' ';

    return 0;
}