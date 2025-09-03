#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0; i<n; i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> order;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v:adj[u]){
            if(--indegree[v]==0) q.push(v);
        }
    }
    
    if(order.size()!=n){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i:order) cout<<i+1<<' ';
    }
    
    return 0;
}
