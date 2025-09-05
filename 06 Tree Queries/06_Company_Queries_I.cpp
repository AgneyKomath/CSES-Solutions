#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    int log = __lg(n) + 1;

    // Binary Lifting Table
    vector<vector<int>> jump(log, vector<int>(n, -1));
    for(int i = 1; i<n; i++){
        cin>>jump[0][i];
        jump[0][i]--;
    }

    for(int i = 1; i<log; i++){
        for(int j = 0; j<n; j++){
            int v = jump[i-1][j];
            if(v==-1) continue;
            jump[i][j] = jump[i-1][v];
        }
    }

    while(q--){
        int u, k;
        cin>>u>>k;
        u--;

        for(int i = log-1; i>=0 && u != -1; i--){
            if(k&(1<<i)) u = jump[i][u];
        }
        if(u != -1) u++;
        
        cout<<u<<'\n';
    }

    return 0;
}