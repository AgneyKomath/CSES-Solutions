#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Tree{
    int root;
    int log2dist, n;
    vector<vector<int>> adj, pow2ends;
    vector<int> parent, depth;

    void process(int curr, int prev){
        depth[curr] = depth[prev] + 1;
        for(int i:adj[curr]){
            if(i==prev) continue;
            process(i, curr);
            parent[i] = curr;
        }
    }

    void build(){
        for(int i = 0; i<n; i++){
            pow2ends[i][0] = parent[i];
        }

        for(int p = 1; p<=log2dist; p++){
            for(int i = 0; i<n; i++){
                int mid = pow2ends[i][p-1];
                if(mid==-1){
                    pow2ends[i][p] = -1;
                }
                else{
                    pow2ends[i][p] = pow2ends[mid][p-1];
                }
            }
        }
    }

    Tree(const vector<vector<int>> &a, int r = 0){
        adj = a;
        n = adj.size();
        log2dist =ceil(log2(n));
        parent.resize(n);
        depth.resize(n);
        pow2ends.resize(n, vector<int>(log2dist+1));

        root = r;
        parent[root] = -1;
        depth[root] = -1;

        process(root, root);
        build();
    }

    int kth_ancestor(int node, int k){
        if(k>n) return -1;
        for(int pow = 0; pow<=log2dist; pow++){
            if((k&(1<<pow))){
                node = pow2ends[node][pow];
                if(node==-1) break;
            }
        }
        return node;
    }

    int lca(int node1, int node2){
        if(depth[node1]<depth[node2]) swap(node1, node2);
        
        node1 = kth_ancestor(node1, depth[node1] - depth[node2]);

        if(node1==node2){
            return node2;
        }
        
        for(int i = log2dist; i>=0; i--){
            if(pow2ends[node1][i] != pow2ends[node2][i]){
                node1 = pow2ends[node1][i];
                node2 = pow2ends[node2][i];
            }
        }

        return pow2ends[node1][0];
    }

    int distance(int node1, int node2){
        int ancestor = lca(node1, node2);
        int res = depth[node1] + depth[node2] - 2*depth[ancestor];
        return res;
    }

    bool is_ancestor(int node1, int node2){
        bool res = lca(node1, node2) == node1;
        return res;
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

    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tree tr(adj);

    vector<int> val(n, 0);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        int lca = tr.lca(u, v);
        val[u]++;
        val[v]++;
        // remove 2*lca but one time remove parent of lca because lca is also in path
        val[lca]--;
        if(tr.parent[lca] != -1) val[tr.parent[lca]]--;
    }

    auto dfs = [&](int node, int par, auto &&dfs)->void{
        for(int i:adj[node]) if(i != par){
            dfs(i, node, dfs);
            val[node] += val[i];
        }
    };
    dfs(0, -1, dfs);

    for(auto i:val) cout<<i<<' ';
    
    return 0;
}
