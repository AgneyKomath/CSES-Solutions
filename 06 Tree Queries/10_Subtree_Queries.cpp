#include <bits/stdc++.h>
using namespace std;

struct BIT{
    //Fenwick Tree by Fusion15
    vector<int> arr;
    vector<long long> tree;
    int n;
    
    void build(vector<int> &a){
        for(int i=0; i<n; i++){
            add(i, a[i]);
        }
    }
    
    BIT(vector<int> &a){
        n = a.size();
        arr.resize(n, 0);
        tree.resize(n+1, 0);
        build(a);
    }
    
    void add(int ind, int val){
        arr[ind] += val;
        for(int i=ind+1; i<=n; i += i&-i){
            tree[i] += val;
        }
    }
    
    void update(int ind, int val){
        int diff = val - arr[ind];
        add(ind, diff);
    }
    
    long long query(int ind){
        long long sum = 0;
        for(int i = ind+1; i>0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }

    long long query(int l, int r){
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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
    vector<int> start(n), end(n), order(n);
    int timer = 0;
    auto dfs = [&](int u, int p, auto &&dfs)->void{
        order[timer] = a[u];
        start[u] = timer++;
        for(int v:adj[u]){
            if(v==p) continue;
            dfs(v, u, dfs);
        }
        end[u] = timer-1;
    };
    dfs(0, -1, dfs);

    BIT bit(order);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int u, val;
            cin>>u>>val;
            u--;
            bit.update(start[u], val);
        }
        else if(t==2){
            int u;
            cin>>u;
            u--;
            cout<<bit.query(start[u], end[u])<<'\n';
        }
    }

    return 0;
}