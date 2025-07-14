#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }

    vector<int> subordinates(n+1,-1);
    auto dfs{[&](int node, auto &self)->int{
        {}
        int res=0;
        for(auto child:adj[node]){
            res += 1+self(child,self);
        }
        subordinates[node] = res;
        return subordinates[node];
    }};

    dfs(1,dfs);
    for(int i=1;i<=n;i++){
        cout<<subordinates[i]<<' ';
    }

    
    
    return 0;
}
