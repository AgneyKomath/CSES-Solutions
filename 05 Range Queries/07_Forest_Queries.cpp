#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<string> a(n);
    for(auto &i:a) cin>>i;

    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + (a[i][j]=='*');
        }
    }

    while(q--){
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        int res = pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
        cout<<res<<'\n';
    }
    
    return 0;
}
