#include <bits/stdc++.h>
#define int long long
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


struct DSU{
    vector<int> f, siz;

    DSU(int n){
        f.resize(n);
        siz.assign(n,1);
        iota(f.begin(),f.end(),0ll);
    }


    int find(int x){
        if(f[x] != x){
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        
        if(x==y){
            return false;
        }
        if(siz[y]>siz[x]){
            swap(x,y);
        }
        f[y] = x;

        siz[x] += siz[y];
        return true;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adjog(n);
    while(m--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adjog[u].push_back(v);
    }

    SCC scc(adjog);

    int sz = scc.comps.size();

    if(sz==1){
        cout<<"0\n";
        return 0;
    }

    vector<set<int>> adj(sz);
    vector<int> indegree(sz, 0), outdegree(sz, 0);
    
    for(int i = 0;i<n;i++){
        int id = scc.comp[i];
        for(auto j:adjog[i]){
            if(scc.comp[i]==scc.comp[j]) continue;
            adj[id].insert(scc.comp[j]);
        }
    }

    DSU dsu(sz);
    for(int i = 0; i<sz; i++){
        for(auto j:adj[i]) dsu.merge(i, j);
    }


    for(int i =0; i<sz ;i++){
        outdegree[i] += adj[i].size();
        for(auto j:adj[i]){
            indegree[j]++;
        }
    }

    vector<int> out0, in0;
    for(int i = 0;i<sz;i++){
        if(!outdegree[i]) out0.push_back(i);
        if(!indegree[i]) in0.push_back(i);
    }

    int res = 0;
    vector<pair<int,int>> edges;
    for(int i = 0; i<1; i++){
        int rep1 = *scc.comps[out0[i]].begin();
        for(int j = 1;j<out0.size(); j++){
            int rep2 = *scc.comps[out0[j]].begin();
            if(dsu.find(out0[i])==dsu.find(out0[j])) continue;
            res++;
            edges.emplace_back(rep2+1, rep1+1);
        }
    }

    for(int i = 0; i<1; i++){
        int rep1 = *scc.comps[out0[i]].begin();
        for(int j = 0;j<in0.size(); j++){
            int rep2 = *scc.comps[in0[j]].begin();
            res++;
            edges.emplace_back(rep1+1, rep2+1);
        }
    }

    cout<<res<<'\n';
    for(auto & [a, b]:edges) cout<<a<<' '<<b<<'\n';


    return 0;
}
