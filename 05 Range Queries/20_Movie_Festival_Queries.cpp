#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    const int mxn = 1e6, log = 20;

    vector<int> a(mxn, mxn);
    for(int i = 0; i<n; i++){
        int s, e;
        cin>>s>>e;
        s--;e--;
        a[s] = min(a[s], e);
    }

    // Binary Lifting
    vector<vector<int>> jump(log, vector<int>(mxn, -1));
    int mn = mxn;
    for(int i = mxn-1; i>=0; i--){
        mn = min(mn, a[i]);
        if(mn != mxn) jump[0][i] = mn;
    }

    // Build Table
    for(int i = 1; i<log; i++){
        for(int j = 0; j<mxn; j++){
            int v = jump[i-1][j];
            if(v==-1) continue;
            jump[i][j] = jump[i-1][v];
        }
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l--;r--;
        
        int curr = l, res = 0;

        // While curr less than r go forward
        for(int i = log-1; i>=0; i--){
            int v = jump[i][curr];
            if(v != -1 && v<=r){
                res += 1<<i;
                curr = v;
            }
        }
        cout<<res<<'\n';
    }
    
    return 0;
}
