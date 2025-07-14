#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin>>n>>m>>q;
    
    vector<vector<long long>> dist(n, vector<long long>(n, 1e18));
    for(int i = 0; i<n; i++) dist[i][i] = 0;

    for(int i = 0; i<m; i++){
        int u, v;
        long long w;
        cin>>u>>v>>w;
        u--;v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(dist[i][k] + dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    while(q--){
        int u, v;
        cin>>u>>v;
        long long d = dist[u-1][v-1];
        if(d==1e18) d = -1;
        cout<<d<<'\n';
    }
    
    return 0;
}
