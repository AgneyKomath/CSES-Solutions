#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> prev(m + 2, 0);
    if(a[0] == 0){
        for(int i = 1; i <= m; i++) prev[i] = 1;
    }
    else prev[a[0]] = 1;

    for(int i = 1; i < n; i++){
        vector<int> curr(m + 2, 0);
        if(a[i] == 0){
            for(int j = 1; j <= m; j++){
                curr[j] = (0ll + prev[j - 1] + prev[j] + prev[j + 1]) % mod;
            }
        }
        else{
            curr[a[i]] = (0ll + prev[a[i] - 1] + prev[a[i]] + prev[a[i] + 1]) % mod;
        }
        swap(prev, curr);
    }

    int res = 0;
    for(int i : prev) res = (res + i) % mod;
    cout<<res;

    return 0;
}
