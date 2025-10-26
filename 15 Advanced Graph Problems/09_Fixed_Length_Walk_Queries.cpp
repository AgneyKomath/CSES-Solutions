#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin>>n>>m>>q;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int INF = 1e9;
    vector<vector<array<int, 2>>> dist(n, vector<array<int, 2>>(n, {INF, INF}));
    auto calc = [&](int st){
        queue<pair<int, int>> que;
        que.push({st, 0});
        dist[st][st][0] = 0;
        
        while(!que.empty()){
            auto [u, par] = que.front();
            que.pop();
            int d = dist[st][u][par];
            for(int v : adj[u]){
                if(dist[st][v][1 - par] <= d + 1) continue;
                dist[st][v][1 - par] = d + 1;
                que.emplace(v, 1 - par);
            }
        }
    };

    for(int i = 0; i < n; i++){
        calc(i);
    }

    while(q--){
        int u, v, d;
        cin>>u>>v>>d;
        u--, v--;
        cout<<(dist[u][v][d & 1] <= d ? "YES" : "NO")<<'\n';
    }

    return 0;
}
