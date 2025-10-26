#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    vector<int> a(k);
    for(int &i : a){
        cin>>i;
        i--;
    } 

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Store 2 closest shops' index, distance
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(2, vector<int>(2, -1)));
    queue<array<int, 3>> q;

    for(int i : a){
        q.push({i, i, 0});
        dist[i][0] = {i, 0};
    }

    while(!q.empty()){
        auto [u, og, d] = q.front();
        q.pop();
        for(int v : adj[u]){
            if(dist[v][0][0] == -1){
                dist[v][0] = {og, d + 1};
                q.push({v, og, d + 1});
            }
            else if(dist[v][0][0] != og && dist[v][1][0] == -1){
                dist[v][1] = {og, d + 1};
                q.push({v, og, d + 1});
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<(dist[i][0][0] == i ? dist[i][1][1] : dist[i][0][1])<<' ';
    }

    return 0;
}
