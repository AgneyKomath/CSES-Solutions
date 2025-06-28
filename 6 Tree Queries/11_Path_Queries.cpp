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

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Euler Tour
    vector<int> tin(n), tout(n);
    int timer = 0;
    auto dfs = [&](int node, int par, auto &&dfs)->void{
        tin[node] = timer++;
        for(int i:adj[node]) if(i != par){
            dfs(i, node, dfs);
        }
        tout[node] = timer;
    };
    dfs(0, -1, dfs);

    //Fenwick Tree
    vector<int> tree(n+2, 0);
    auto add = [&](int ind, int val){
        for(int i = ind+1; i<=n+1; i += i&-i){
            tree[i] += val;
        }
    };
    auto sum = [&](int ind){
        int res = 0;
        for(int i = ind+1; i; i -= i&-i){
            res += tree[i];
        }
        return res;
    };

    // Difference Array
    for(int i = 0; i<n; i++){
        add(tin[i], +a[i]);
        add(tout[i], -a[i]);
    }

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int s, x;
            cin>>s>>x;
            s--;
            int prev = a[s];
            add(tin[s], x - prev);
            add(tout[s], prev - x);
            a[s] = x;
        }
        else{
            int s;
            cin>>s;
            s--;
            // root to node sum
            cout<<sum(tin[s])<<'\n';
            // for node to node path do sum(a) + sum(b) - 2 * sum(lca(a, b)) + val(lca(a, b))
        }
    }
    
    return 0;
}
