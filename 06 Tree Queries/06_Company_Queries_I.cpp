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
    for(int i = 1; i < n; i++){
        int u;
        cin>>u;
        jump[0][i] = u - 1;
    }

    for(int i = 1; i < log; i++){
        for(int j = 0; j < n; j++){
            if(jump[i - 1][j] == -1) continue;
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }

    while(q--){
        int u, k;
        cin>>u>>k;
        u--;
        for(int i = log - 1; i >= 0 && u != -1; i--){
            if((k >> i) & 1){
                u = jump[i][u];
            }
        }
        cout<<(u == -1 ? -1 : u + 1)<<'\n';
    }

    return 0;
}
