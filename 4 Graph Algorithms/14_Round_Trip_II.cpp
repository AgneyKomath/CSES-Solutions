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

    while(m--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }


    vector<int> visited(n,0);
    vector<int> parent(n,-1);
    vector<int> res;

    auto dfs = [&](int u, auto &&self){
        visited[u] = 1;

        for(auto i:adj[u]){
            if(visited[i]==2) continue;
            else if(visited[i]==1){
                //cycle
                res.push_back(i);
                
                int tp = u;
                while(tp != i){
                    res.push_back(tp);
                    tp = parent[tp];
                }
                res.push_back(i);
                
                return true;
            }
            
            parent[i] = u;
            if(self(i, self)) return true;
        }

        visited[u] = 2; 
        return false;
    };

    for(int node = 0;node<n;node++){
        if(visited[node]) continue;
    
        if(dfs(node, dfs)){
            reverse(res.begin(), res.end());
            cout<<res.size()<<'\n';
            for(auto i:res) cout<<i+1<<' ';
            return 0;
        }
    }

    cout<<"IMPOSSIBLE\n";
    
    
    return 0;
}
