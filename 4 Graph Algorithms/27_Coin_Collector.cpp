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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;
    vector<int> coinsog(n);
    for(auto &i:coinsog) cin>>i;

    vector<vector<int>> adjog(n);
    while(m--){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adjog[u].push_back(v);
    }

    SCC scc(adjog);

    int sz = scc.comps.size();

    vector<set<int>> adj(sz);
    vector<int> coins(sz, 0);
    
    for(int i = 0;i<n;i++){
        int id = scc.comp[i];
        coins[id] += coinsog[i];
        for(auto j:adjog[i]){
            if(scc.comp[i]==scc.comp[j]) continue;
            adj[id].insert(scc.comp[j]);
        }
    }

    vector<int> dp(sz, -1);

    auto dfs = [&](int node, auto &&self){
        if(dp[node]!=-1) return dp[node];

        int res = 0;
        for(auto j:adj[node]){
            res = max(res, self(j, self));
        }
        res += coins[node];
        return dp[node] = res;
    };

    int res = 0;
    for(int i = 0;i<sz;i++){
        res = max(res, dfs(i, dfs));
    }

    cout<<res;
    
    return 0;
}
