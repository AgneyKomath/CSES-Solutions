#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    
    while(m--){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i =0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int tp = q.front(); q.pop();
        topo.push_back(tp);

        for(int i:adj[tp]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }

    if(topo.size()!=n){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i:topo) cout<<i+1<<' ';
    }
    
    return 0;
}
