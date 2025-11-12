#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    const int MXN = 1e6, LOG = 20;

    vector<int> a(MXN + 1, MXN);
    for(int i = 0; i < n; i++){
        int s, e;
        cin>>s>>e;
        s--, e--;
        a[s] = min(a[s], e);
    }

    vector<vector<int>> table(LOG, vector<int>(MXN + 1, MXN));
    for(int i = MXN - 1; i >= 0; i--){
        a[i] = min(a[i], a[i + 1]);
        table[0][i] = a[i];
    }

    for(int i = 1; i < LOG; i++){
        for(int j = 0; j < MXN; j++){
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;

        int res = 0;
        for(int i = LOG - 1; i >= 0; i--){
            if(table[i][l] <= r){
                res += 1 << i;
                l = table[i][l];
            }
        }
        cout<<res<<'\n';
    }

    return 0;
}
