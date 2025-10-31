#include <bits/stdc++.h>
using namespace std;

struct SCC{
    //SCC by Fusion15
    vector<vector<int>> adj, rev;
    vector<int> path;
    vector<int> comp;
    vector<vector<int>> comps;
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
            comps[curr].push_back(node);
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

    int n, m;
    cin>>m>>n;

    vector<vector<int>> adjog(2 * n);
    for(int i = 0; i < m; i++){
        char s1, s2;
        int t1, t2;
        cin>>s1>>t1>>s2>>t2;
        t1--, t2--;
        int n1 = 2 * t1 | (s1 == '+' ? 0 : 1);
        int n2 = 2 * t2 | (s2 == '+' ? 0 : 1);
        adjog[n1 ^ 1].push_back(n2);
        adjog[n2 ^ 1].push_back(n1);        
    }

    SCC scc(adjog);

    for(int i = 0; i < n; i++){
        if(scc.comp[2 * i] == scc.comp[2 * i + 1]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    int sz = scc.comps.size();
    vector<vector<int>> adj(sz);
    vector<int> indeg(sz, 0);
    for(int i = 0; i < sz; i++){
        for(int u : scc.comps[i]){
            for(int v : adjog[u]){
                if(scc.comp[u] == scc.comp[v]) continue;
                adj[i].push_back(scc.comp[v]);
            }
        }
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
        for(int j : adj[i]) indeg[j]++;
    }

    queue<int> q;
    for(int i = 0; i < sz; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vector<int> order(sz);
    int timer = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order[u] = timer++;
        for(int v : adj[u]){
            if(--indeg[v] == 0){
                q.push(v);
            }
        }
    }

    for(int i = 0; i < n; i++){
        int c1 = scc.comp[2 * i], c2 = scc.comp[2 * i + 1];
        if(order[c1] < order[c2]) cout<<"- ";
        else cout<<"+ ";
    }

    return 0;
}
