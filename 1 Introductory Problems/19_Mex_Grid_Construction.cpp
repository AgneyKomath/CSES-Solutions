#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin>>n;
    
    vector<vector<bool>> rows(n, vector<bool>(2*n, 0)), cols(n, vector<bool>(2*n, 0));
    auto mex = [&](vector<bool> &a, vector<bool> &b){
        for(int i = 0; i<2*n; i++){
            if(!a[i] && !b[i]) return i;
        }
        return 2*n+1;
    };

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int v = mex(rows[i], cols[j]);
            rows[i][v] = 1;
            cols[j][v] = 1;
            cout<<v<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
