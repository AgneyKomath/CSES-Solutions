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

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }
    
    SCC scc(adj);

    cout<<scc.comps.size()<<'\n';
    for(int i:scc.comp) cout<<i+1<<' ';
    
    return 0;
}
