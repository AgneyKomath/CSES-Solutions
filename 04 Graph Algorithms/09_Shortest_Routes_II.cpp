#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin>>n>>m>>q;

    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        dist[u][v] = min(dist[u][v], (ll)w);
        dist[v][u] = min(dist[v][u], (ll)w);
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--){
        int u, v;
        cin>>u>>v;
        u--, v--;
        cout<<(dist[u][v] == INF ? -1 : dist[u][v])<<'\n';
    }

    return 0;
}
