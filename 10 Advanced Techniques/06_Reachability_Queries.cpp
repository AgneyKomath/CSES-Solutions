#include <bits/stdc++.h>
using namespace std;

struct SCC{
    //SCC by Fusion15
    vector<vector<int>> adj, rev;
    vector<int> path;
    vector<int> comp;
    vector<set<int>> comps;
    int n;

    void buildrev(){
        for(int i = 0; i<n; i++){
            for(int j:adj[i]){
                rev[j].push_back(i);
            }
        }
    }

    SCC(vector<vector<int>> &a){
        n = a.size();
        adj = a;
        rev.resize(n);
        comp.resize(n, -1);

        buildrev();
        dfs1();
        dfs2();
    }

    void dfs1(){
        vector<bool> vis(n, 0);
        
        auto dfs = [&](int node, auto &&self){
            if(vis[node]) return;
            vis[node] = 1;
            for(auto j:adj[node]){
                self(j, self);
            }    
            path.push_back(node);
        };

        for(int i = 0;i<n;i++) dfs(i, dfs);
        reverse(path.begin(), path.end());
    }

    void dfs2(){
        vector<bool> vis(n, 0);
        
        auto dfs = [&](int node, int curr, auto &&self){
            if(vis[node]) return;
            comp[node] = curr;
            comps[curr].insert(node);
            vis[node] = 1;
            for(auto j:rev[node]){
                self(j, curr, self);
            }
        };

        int curr = 0;
        for(int i:path){
            if(comp[i]==-1){
                comps.emplace_back();
                dfs(i, curr, dfs);
                curr++;
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, quer;
    cin>>n>>m>>quer;

    vector<vector<int>> adjog(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adjog[u].push_back(v);
    }

    SCC scc(adjog);

    int sz = scc.comps.size();
    vector<set<int>> adj(sz);
    
    for(int i = 0; i<n; i++){
        int id = scc.comp[i];
        for(int j:adjog[i]){
            if(scc.comp[i]==scc.comp[j]) continue;
            adj[id].insert(scc.comp[j]);
        }
    }

    vector<int> indegree(sz, 0);
    for(int i = 0; i<sz; i++){
        for(int j:adj[i]){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<sz; i++){
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

    vector<bitset<50000>> dp(sz);
    for(int i = sz - 1; i>=0; i--){
        int u = order[i];
        for(int v:adj[u]) dp[u] |= dp[v];
        dp[u].set(u);
    }

    while(quer--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        u = scc.comp[u], v = scc.comp[v];
        cout<<(dp[u][v] ? "YES" : "NO")<<'\n';
    }
    
    return 0;
}
