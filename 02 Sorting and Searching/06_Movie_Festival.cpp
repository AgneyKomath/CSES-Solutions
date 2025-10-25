#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> a(n);
    for(auto &[e, s] : a) cin>>s>>e;

    sort(a.begin(), a.end());

    int res = 0, prev = 0;
    for(auto [e, s] : a){
        if(s >= prev){
            res++;
            prev = e;
        }
    }

    cout<<res;

    return 0;
}
