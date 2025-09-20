#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<string> a(n);
    for(auto &i:a) cin>>i;

    vector<vector<long long>> prev(n+1, vector<long long>(k, 0)), curr(n+1, vector<long long>(k, 0));
    vector<long long> res(k, 0);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int id = a[i][j] - 'A';
            curr[j+1][id] = min({prev[j+1][id], curr[j][id], prev[j][id]}) + 1;
            res[id] += curr[j+1][id];
        }
        swap(prev, curr);
        for(auto &i:curr) i.assign(26, 0);
    }

    for(auto i:res) cout<<i<<'\n';

    return 0;
}
