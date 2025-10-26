#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int INF = 1e9;

    auto check = [&](int i)->int{
        vector<int> dist(n, INF);
        queue<pair<int, int>> q;
        q.push({i, -1});
        dist[i] = 0;
        
        int d = 0, res = INF;
        while(!q.empty()){
            d++;
            int sz = q.size();
            while(sz--){
                auto [u, p] = q.front();
                q.pop();
                for(int v : adj[u]){
                    if(v == p) continue;
                    if(dist[v] == INF){
                        dist[v] = d;
                        q.emplace(v, u);
                    }
                    else{
                        res = min(res, dist[v] + d);
                    }
                }
            }
        }
        return res;
    };

    int res = INF;
    for(int i = 0; i < n; i++){
        res = min(res, check(i));
    }

    cout<<(res == INF ? -1 : res);

    return 0;
}
